
/**
 * The base address of the QSM register.
 */
#define QSM_BASE_ADDRESS 0xFFFC00

/**
 * Defines the QSMCR (QSM Module configuration) register bit mask.
 */
enum QSMCR {
	STOP = 1<<15,
	FRZ1 = 1<<14,
	FRZ0 = 1<<13,
	SUPV = 1<<7,
	IARB = 0xF
};

/**
 * Defines the QILR (QSM Interrupt level) register bit mask.
 */
enum QILR {
	ILQSPI      = 3,
	ILQSPI_MASK = 0x7 << ILQSPI,
	ILSCI       = 0,
	ILSCI_MASK  = 0x7 << ILSCI
};

/**
 * Defines the SCCR0 (SCI Control 0) register bit mask.
 */
enum SCCR0 {
	SCBR = 0x1FFF
};

/**
 * Defines the SCCR1 (SCI Control 1) register bit mask.
 */
enum SCCR1 {
	Loops = 1<<14,
	Wooms = 1<<13,
	ILT   = 1<<12,
	PT    = 1<<11,
	PE    = 1<<10,
	M     = 1<<9,
	WAKE  = 1<<8,
	TIE   = 1<<7,
	TCIE  = 1<<6,
	RIE   = 1<<5,
	ILIE  = 1<<4,
	TE    = 1<<3,
	RE    = 1<<2,
	RWU   = 1<<1,
	SBK   = 1<<0
};

/**
 * Defines the SCSR (SCI Status) register bit mask.
 */
enum SCSR {
	TDRE = 1<<8,
	TC   = 1<<7,
	RDRF = 1<<6,
	RAF  = 1<<5,
	IDLE = 1<<4,
	OR   = 1<<3,
	NF   = 1<<2,
	FE   = 1<<1,
	PF   = 1<<0
};

/**
 * Defines the SCSR (SCI Data) register bit mask.
 */
enum SCDR {
	RT8 = 1<<8,
	RT7 = 1<<7,
	RT6 = 1<<6,
	RT5 = 1<<5,
	RT4 = 1<<4,
	RT3 = 1<<3,
	RT2 = 1<<2,
	RT1 = 1<<1,
	RT0 = 1<<0
};


struct QSM {
	unsigned short int QSMCR;
	unsigned short int QSTEST;
	unsigned char QILR;
	unsigned char QIVR;
	unsigned short int _;
	unsigned short int SCCR0;
	unsigned short int SCCR1;
	unsigned short int SCSR;
	unsigned short int SCDR;
};

enum ParityConfig {
	DISABLED,
	EVEN,
	ODD
};

struct SerialConfig {
	unsigned int baudrate;
	enum ParityConfig parity;
};

