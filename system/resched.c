/* resched.c - resched, resched_cntl */

#include <xinu.h>

struct	deferent	defertab[NCORE];

/*------------------------------------------------------------------------
 *  resched  -  Reschedule processor to highest priority eligible process
 *------------------------------------------------------------------------
 */
void	resched(void)		/* Assumes interrupts are disabled	*/
{
	struct procent *ptold;		/* Ptr to table entry for old process	*/
	struct procent *ptnew;		/* Ptr to table entry for new process	*/
	struct deferent *dfrptr;	/* Ptr to defer entry for this core		*/
	struct cpident *cpidptr;	/* Ptr to current pid entry				*/
	cid32 thiscore;				/* ID of currently running core			*/

	thiscore = getcid();
	cpidptr = &cpidtab[thiscore];
	dfrptr = &defertab[thiscore];

	/* If rescheduling is deferred, record attempt and return */

	if (dfrptr->ndefers > 0) {
		dfrptr->attempt = TRUE;
		return;
	}

	/* Point to process table entry for the current (old) process */
	ptold = &proctab[cpidptr->cpid];

	if (ptold->prstate == PR_CURR) {  /* Process remains eligible */
		if (ptold->prprio > firstkey(readylist)) {
			return;
		}

		/* Old process will no longer remain current */

		ptold->prstate = PR_READY;
		insert(cpidptr->cpid, readylist, ptold->prprio);
	}

	/* Force context switch to highest priority ready process */

	cpidptr->cpid = dequeue(readylist);
	ptnew = &proctab[cpidptr->cpid];
	ptnew->prstate = PR_CURR;
	preempt = QUANTUM;		/* Reset time slice for process	*/
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);

	/* Old process returns here when resumed */

	return;
}

/*------------------------------------------------------------------------
 *  resched_cntl  -  Control whether rescheduling is deferred or allowed
 *------------------------------------------------------------------------
 */
status	resched_cntl(		/* Assumes interrupts are disabled	*/
	  int32	defer		/* Either DEFER_START or DEFER_STOP	*/
	)
{
	struct deferent *dfrptr;	/* Ptr to defer entry for this core		*/

	dfrptr = &defertab[getcid()];

	switch (defer) {

	    case DEFER_START:	/* Handle a deferral request */

		if (dfrptr->ndefers++ == 0) {
			dfrptr->attempt = FALSE;
		}
		return OK;

	    case DEFER_STOP:	/* Handle end of deferral */
		if (dfrptr->ndefers <= 0) {
			return SYSERR;
		}
		if ( (--dfrptr->ndefers == 0) && dfrptr->attempt ) {
			resched();
		}
		return OK;

	    default:
		return SYSERR;
	}
}
