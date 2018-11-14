/* allwinner_eth.h - Ethernet device definitions for Allwinner SoC */

	/*register name			offset	description*/
struct __attribute__((packed)) eth_aw_csreg {
	reg32 basic_ctl_0;	/* 0x00	Basic control 0 */
	reg32 basic_ctl_1;	/* 0x04	Basic control 1 */
	reg32 int_sta;			/* 0x08	Interrupt status */
	reg32 int_en;				/* 0x0C	Interrupt enable */
	reg32 tx_ctl_0;			/* 0x10	Transmit control 0 */
	reg32 tx_ctl_1;			/* 0x14	Transmit control 1 */
	byte res0[4];
	reg32 tx_flow_ctl;	/* 0x1C	Transmit flow control */
	reg32 tx_dma_desc_list;	/* 0x20	Transmit descriptor list address */
	reg32 rx_ctl_0;			/* 0x24	Receive control 0 */
	reg32 rx_ctl_1;			/* 0x28	Receive control 1 */
	byte res1[8];
	reg32 rx_dma_desc_list;	/* 0x34	Receive descriptor list address */
	reg32 rx_frm_flt;		/* 0x38	Receive frame filter */
	byte res2[4];
	reg32 rx_hash_0;		/* 0x40	Hash table 0 */
	reg32 rx_hash_1;		/* 0x44	Hash table 1 */
	reg32 mii_cmd;			/* 0x48	Management interface command */
	reg32 mii_data;			/* 0x4C	Management interface data */
	reg32 addr0_high;		/* 0x50	MAC address high 0 */
	reg32 addr0_low;		/* 0x54	MAC address low 0 */
	reg32 addr1_high;		/* 0x58	MAC address high 1 */
	reg32 addr1_low;		/* 0x5C	MAC address low 1 */
	reg32 addr2_high;		/* 0x60	MAC address high 2 */
	reg32 addr2_low;		/* 0x64	MAC address low 2 */
	reg32 addr3_high;		/* 0x68	MAC address high 3 */
	reg32 addr3_low;		/* 0x6C	MAC address low 3 */
	reg32 addr4_high;		/* 0x70	MAC address high 4 */
	reg32 addr4_low;		/* 0x74	MAC address low 4 */
	reg32 addr5_high;		/* 0x78	MAC address high 5 */
	reg32 addr5_low;		/* 0x7C	MAC address low 5 */
	reg32 addr6_high;		/* 0x80	MAC address high 6 */
	reg32 addr6_low;		/* 0x84	MAC address low 6 */
	reg32 addr7_high;		/* 0x88	MAC address high 7 */
	reg32 addr7_low;		/* 0x8C	MAC address low 7 */
	byte res3[32];
	reg32 tx_dma_sta;	/* 0xB0	Transmit dma status */
	reg32 tx_cur_desc;	/* 0xB4	Current transmit descriptor */
	reg32 tx_cur_buf;	/* 0xB8	Current transmit buffer address */
	byte res4[4];
	reg32 rx_dma_sta;	/* 0xC0	Receive dma status */
	reg32 rx_cur_desc;	/* 0xC4	Current receive descriptor */
	reg32 rx_cur_buf;	/* 0xC8	Current receive buffer address */
	byte res5[4];
	reg32 rgmii_sta;	/* 0xD0	RGMII status register */
};

/*	Name			Value		Description */
/* basic_ctl_0 signals */

#define ETH_AW_CTL_100MB	0x0000000C	/* Set for 100 Mbps */
#define ETH_AW_CTL_10MB		0x00000008	/* Set for 10 Mbps */
#define ETH_AW_CTL_LOOPBACK	0x00000002	/* Off by default */
#define	ETH_AW_CTL_DUPLEX	0x00000001	/* Set for full duplex */

/* basic_ctl_1 signals */

#define ETH_AW_BURST_LEN	0x0000003F	/* Mask for BURST_LEN */
#define ETH_AW_RX_TX_PRI	0x00000002	/* Set to prioritize RX */
#define ETH_AW_SOFT_RST		0x00000001	/* Soft reset */

/* int_sta signals (off or 0 by default) */

#define ETH_AW_RGMII_LINK_STA_INT	\
				0x00010000	/* Link status of RGMII changed */
#define ETH_AW_RX_EARLY_INT	0x00002000	/* RX DMA filled first buffer */
#define ETH_AW_RX_OVERFLOW_INT	0x00001000	/* RX FIFO overflowed */
#define ETH_AW_RX_TIMEOUT_INT	0x00000800	/* Received frame is too long */
#define ETH_AW_RX_DMA_STOPPED_INT	\
				0x00000400	/* RX DMA FSM is stopped */
#define ETH_AW_RX_BUF_UA_INT	0x00000200	/* RX DMA is suspended */
#define ETH_AW_RX_INT		0x00000100	/* Frame reception is completed */
#define ETH_AW_TX_EARLY_INT	0x00000020	/* Frame is transmitted to FIFO */
#define ETH_AW_TX_UNDERFLOW_INT	0x00000010	/* TX FIFO underflowed */
#define ETH_AW_TX_TIMEOUT_INT	0x00000008	/* TX has timed out */
#define ETH_AW_TX_BUF_UA_INT	0x00000004	/* TX DMA is suspended */
#define ETH_AW_TX_DMA_STOPPED_INT	\
				0x00000002	/* TX DMA FSM is stopped */
#define ETH_AW_TX_INT		0x00000001	/* Frame completion */

/* int_en signals  (off or 0 by default) */

#define ETH_AW_RX_EARLY_INT_EN	0x00002000	/* Early rx interrupt enable */
#define ETH_AW_RX_OVERFLOW_INT_EN	\
				0x00001000	/* Overflow interrupts */
#define ETH_AW_RX_TIMEOUT_INT_EN	\
				0x00000800	/* Rx timeout interrupts */
#define ETH_AW_RX_DMA_STOPPED_INT_EN	\
				0x00000400	/* Rx DMA FSM stopped interrupts */
#define ETH_AW_RX_BUF_UA_INT_EN	0x00000200	/* Rx buffer unavailable interrupt */
#define ETH_AW_RX_INT_EN	0x00000100	/* Rx interrupts */
#define ETH_AW_TX_EARLY_INT_EN	0x00000020	/* Early tx interrupts */
#define ETH_AW_TX_UNDERFLOW_INT_EN	\
				0x00000010	/* Underflow interrupts */
#define ETH_AW_TX_TIMEOUT_INT_EN	\
				0x00000008	/* Tx timeout interrupts */
#define ETH_AW_TX_BUF_UA_INT_EN	0x00000004	/* Tx buffer available interrupt */
#define ETH_AW_TX_DMA_STOPPED_INT_EN	\
				0x00000002	/* Tx DMA FSM stopped interrupts */
#define ETH_AW_TX_INT_EN	0x00000001	/* Tx interrupts */

/* tx_ctl_0 signals */

#define ETH_AW_TX_EN		0x80000000	/* Toggle transmitter */
#define ETH_AW_TX_FRM_LEN_CTL	0X40000000	/* Tx frames <= 2048 bytes */

/* tx_ctl_1 signals */

#define ETH_AW_TX_DMA_START	0x80000000	/* Start the TX DMA FSM */
#define ETH_AW_TX_DMA_EN	0x40000000	/* Start TX DMA, clear to stop TX DMA after the current frame is transmitted */
#define ETH_AW_TX_TH_64		0x00000700	/* Clear for 64 */
#define ETH_AW_TX_TH_128	0x00000100	/* Set for 128 */
#define ETH_AW_TX_TH_192	0x00000200	/* Set for 192 */
#define ETH_AW_TX_TH_256	0x00000300	/* Set for 256 */
#define ETH_AW_TX_MD		0x00000002	/* Start tx when a full frame is read in TX DMA FIFO, otherwise tx starts after the data in TX DMA FIFO goes over the threshold. */
#define ETH_AW_FLUSH_TX_FIFO	0x00000001	/* Disable flushing the TX FIFO */

/* tx_flow_ctl signals */

#define ETH_AW_TX_FLOW_CTL_STA	0x80000000	/* Trasmit a pause frame */
#define ETH_AW_TX_PAUSE_FRM_SLOT	\
				0x00300000	/* Threshold of pause timer */
#define ETH_AW_PAUSE_TIME	0x000FFFF0	/* Pause time for control frame */
#define ETH_AW_ZQP_FRM_EN	0x00000002	/* Generate Zero-Quanta Pause control frame */
#define ETH_AW_TX_FLOW_CTL_EN	0x00000001	/* Toggle flow control operations */

/* TX_DMA_LIST accepts a 32 bit address of the transmit descriptor list. */

/* rx_ctl_0 signals */

#define ETH_AW_RX_EN		0x80000000	/* Toggle receiver */
#define ETH_AW_RX_FRM_LEN_CTL	0x40000000	/* Receive frames <= 16384 bytes */
#define ETH_AW_JUMBO_FRM_EN	0x20000000	/* Allow frames <= 9018 bytes */
#define ETH_AW_STRIP_FCS	0x10000000	/* Strip the Pad/FCS when length < 1500 */
#define ETH_AW_CHECK_CRC	0x08000000	/* Calculate CRC and IPV4 Header Checksum */
#define ETH_AW_RX_PAUSE_FRM_MD	0x00020000	/* See documentation */
#define ETH_AW_RX_FLOW_CTL_EN	0x00010000	/* See documentation */

/* rx_ctl_1 signals */

#define ETH_AW_RX_DMA_START	0x80000000	/* Start the RX DMA */
#define ETH_AW_RX_DMA_EN	0x40000000	/* Start the RX DMA, clear to stop the RX DMA after the current frame is received */
#define ETH_AW_RX_FIFO_FLOW_CTL	0x01000000	/* Rx flow control */
#define ETH_AW_RX_FLOW_CTL_TH_DEACT_1	\
				0x00C00000	/* Clear for 1 */
#define ETH_AW_RX_FLOW_CTL_TH_DEACT_2	\
				0x00400000	/* Set for 2 */
#define ETH_AW_RX_FLOW_CTL_TH_DEACT_3	\
				0x00800000	/* Set for 3 */
#define ETH_AW_RX_FLOW_CTL_TH_DEACT_4	\
				0x00C00000	/* Set for 4 */
#define ETH_AW_RX_FLOW_CTL_TH_ACT_1	\
				0x00300000	/* Clear for 1 */
#define ETH_AW_RX_FLOW_CTL_TH_ACT_2	\
				0x00100000	/* Set for 2 */
#define ETH_AW_RX_FLOW_CTL_TH_ACT_3	\
				0x00200000	/* Set for 3 */
#define ETH_AW_RX_FLOW_CTL_TH_ACT_4	\
				0x00300000	/* Set for 4 */
#define ETH_AW_RX_TH_64		0x00000030	/* Clear for 64 */
#define ETH_AW_RX_TH_32		0x00000010	/* Set for 32 */
#define ETH_AW_RX_TH_96		0x00000020	/* Set for 96 */
#define ETH_AW_RX_TH_128	0x00000030	/* Set for 128 */
#define ETH_AW_RX_ERR_FRM	0x00000008	/* Forward frames with errors */
#define ETH_AW_RUNT_FRM		0x00000004	/* Forward undersized frames */
#define ETH_AW_RX_MD		0x00000002	/* See documentation */
#define ETH_AW_FLUSH_RX_FRM	0x00000001	/* Disable flushing frames when buffers are unavailable */

/* rx_dma_list accepts a 32 bit address of the receiver descriptor list. */

/* rx_frm_flt signals */

#define ETH_AW_DIS_ADDR_FILTER	0x80000000	/* Disable address filter */
#define ETH_AW_DIS_BROADCAST	0x00020000	/* Drop all broadcast frames */
#define ETH_AW_RX_ALL_MULTICAST	0x00010000	/* Receive all multicast frames */
#define ETH_AW_CTL_FRM_FILTER_DROP	\
				0x00003000	/* Clear to drop control frames */
#define ETH_AW_CTL_FRM_FILTER_RECEIVE	\
				0x00002000	/* Receive all control frames */
#define ETH_AW_CTL_FRM_FILTER_PASS	\
				0x00003000	/* Receive control frames that pass the address filter*/
#define ETH_AW_HASH_MULTICAST	0x00000200	/* Filter by hash table  */
#define ETH_AW_HASH_UNICAST	0x00000100	/* Filter by hash table */
#define ETH_AW_SA_FILTER_EN	0x00000080	/* Update SA filter result */
#define ETH_AW_SA_INV_FILTER	0x00000040	/* Inverse filtering */
#define ETH_AW_DA_INV_FILTER	0x00000020	/* Inverse filtering */
#define ETH_AW_FLT_MD		0x00000002	/* Receive frame when it passes the filter */
#define ETH_AW_RX_ALL		0x00000001	/* Receive all frames */

/* rx_hash_0 holds the upper 32 bits of the hash table for the receive frame filter */

/* rx_hash_1 holds the lower 32 bits of the hash table for the receive frame filter */

/* mii_cmd signals */
#define ETH_AW_MDC_DIV_RATIO_M_16	\
				0x00700000	/* Clear for 16 */
#define ETH_AW_MDC_DIV_RATIO_M_32	\
				0x00100000	/* Set for 32 */
#define ETH_AW_MDC_DIV_RATIO_M_64	\
				0x00200000	/* Set for 64 */
#define ETH_AW_MDC_DIV_RATIO_M_128	\
				0x00300000	/* Set for 128 */
/* bits 12-16 are for selecting a PHY device */
#define ETH_AW_MII_ADDR		12
#define ETH_AW_MII_REG		4
#define ETH_AW_PHY_ADDR		1
/* bits 4-8 are for selecting a register in that PHY device */
#define ETH_AW_MII_WR			0x00000002	/* Reading or Write PHY register */
#define ETH_AW_MII_BUSY		0x00000001	/* R/W in progress */

/* mii_data holds data in bits 0-15 that can be written or read from the selected PHY register */
#define ETH_AW_MII_DATA		0x0000ffff	/* Use to read and write data */

/* addrX_high holds the upper 16 bits of the Xth mac address in bits 0-15 */
/* addrX_low holds the lower 32 bits of the Xth mac address */

/* tx_dma_sta signals */
#define ETH_AW_TX_DMA_STA	0x00000007	/* Receive value */

/* tx_dma_cur_desc holds the address of the current descriptor */

/* tx_dma_cur_buf holds the address of the current buffer */

/* rx_dma_sta signals */
#define ETH_AW_RX_DMA_STA	0x00000007	/* Receive value */

/* rx_dma_cur_desc holds the address of the current descriptor */

/* rx_dma_cur_buf holds the address of the current buffer */

/* rgmii_sta signals */
#define ETH_AW_RGMII_LINK	0x00000008	/* Indicates link status */
#define ETH_AW_RGMII_LINK_SP	0x00000006	/* Receive link speed */
#define ETH_AW_RGMII_LINK_MD	0x00000001	/* Indicates link mode */

/* Receiving buffer description structure */
struct eth_aw_rx_desc {
	uint32 status;
	uint32 buf_len;
	uint32 buf_addr;
	struct eth_aw_rx_desc * next;
};

/* rx status signals */
#define ETH_AW_RX_DESC_CTL	0x80000000	/* Usable by DMA */
#define ETH_AW_RX_DAF_FAIL	0x40000000	/* Frame failed DA filter */
#define ETH_AW_RX_FRM_LEN	0x3FFF0000	/* Frame length */
#define ETH_AW_RX_NO_ENOUGH_BUF_ERR	\
				0x00004000	/* Not enough buffer for the frame */
#define ETH_AW_RX_SAF_FAIL	0x00002000	/* Frame failed SA filter */
#define ETH_AW_RX_OVERFLOW_ERR	0x00000800	/* Buffer overflow occurred */
#define ETH_AW_RX_FIR_DESC	0x00000200	/* First descriptor */
#define ETH_AW_RX_LAST_DESC	0x00000100	/* Last descriptor */
#define ETH_AW_RX_HEADER_ERR	0x00000080	/* Wrong checksum */
#define ETH_AW_RX_COL_ERR	0x00000040	/* Late collision */
#define ETH_AW_RX_LENGTH_ERR	0x00000010	/* Wrong frame length */
#define ETH_AW_RX_PHY_ERR	0x00000008	/* PHY sent an error signal */
#define ETH_AW_RX_CRC_ERR	0x00000002	/* CRC of received frame is wrong */
#define ETH_AW_RX_PAYLOAD_ERR	0x00000001	/* Checksum or length of payload is wrong */

/* rx size description signals */
#define ETH_AW_RX_INT_CTL	0x80000000	/* See documentation */
#define ETH_AW_RX_BUF_SIZE	0x000007FF	/* Buffer size */

/* rx buf_addr holds the address of the current descriptor */

/* rx next holds the address of the next descriptor, 32 bit aligned */

/* Transmitting buffer description structure */
struct eth_aw_tx_desc {
	uint32 status;
	uint32 buf_len;
	uint32 buf_addr;
	struct eth_aw_tx_desc * next;
};

/* tx status signals */
#define ETH_AW_TX_DESC_CTL	0x80000000	/* Usable by DMA */
#define ETH_AW_TX_HEADER_ERR	0x00010000	/* Wrong checksum */
#define ETH_AW_TX_LENGTH_ERR	0x00004000	/* Wrong frame length */
#define ETH_AW_TX_PAYLOAD_ERR	0x00001000	/* Checksum or length of payload is wrong */
#define ETH_AW_TX_CRS_ERR	0x00000400	/* Carrier is lost during transmission */
#define ETH_AW_TX_COL_ERR_0	0x00000200	/* See documentation */
#define ETH_AW_TX_COL_ERR_1	0x00000100	/* See documentation */
#define ETH_AW_TX_COL_CNT	0x00000078	/* Number of collisions before transmission */
#define ETH_AW_TX_DEFER_ERR	0x00000004	/* Abort frame due to deferal */
#define ETH_AW_TX_UNDERFLOW_ERR	0x00000002	/* Abort frame due to TX FIFO underflow */
#define ETH_AW_TX_DEFER		0x00000001	/* In half duplex, EMAC defers to transmission */

/* tx buf_len signals */
#define ETH_AW_TX_INT_CTL	0x80000000	/* See documentation */
#define ETH_AW_TX_LAST_DESC	0X40000000	/* Last descriptor */
#define ETH_AW_TX_FIR_DESC	0x20000000	/* First descriptor */
#define ETH_AW_CHECKSUM_CTL	0x18000000	/* Insert checksums in transmit frame */
#define ETH_AW_CRC_CTL		0x04000000	/* Don't transmit CRC field */
#define ETH_AW_TX_BUF_SIZE	0x000007FF	/* Buffer size */

/* tx buf_adr holds the address of the current descriptor */

/* rx next holds the address of the next descriptor, 32 bit aligned */

#define ETH_AW_INIT_DELAY	1000000

#define ETH_AW_RXINT		41
#define ETH_AW_TXINT		42