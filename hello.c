typedef unsigned char u1;
typedef unsigned int u4;

struct u4bits_t
{
  unsigned b0:1;
  unsigned b1:1;
  unsigned b2:1;
  unsigned b3:1;
  unsigned b4:1;
  unsigned b5:1;
  unsigned b6:1;
  unsigned b7:1;
  unsigned b8:1;
  unsigned b9:1;
  unsigned b10:1;
  unsigned b11:1;
  unsigned b12:1;
  unsigned b13:1;
  unsigned b14:1;
  unsigned b15:1;
  unsigned b16:1;
  unsigned b17:1;
  unsigned b18:1; 
  unsigned b19:1;
  unsigned b20:1;
  unsigned b21:1;
  unsigned b22:1;
  unsigned b23:1;
  unsigned b24:1;
  unsigned b25:1;
  unsigned b26:1;
  unsigned b27:1;
  unsigned b28:1;
  unsigned b29:1;
  unsigned b30:1;
  unsigned b31:1;
};
    
struct gpio_t 
{
  struct 
  {
    struct 
    {
      unsigned minor:6;
      unsigned custom:2;
      unsigned major:3;
      unsigned rtl:5;
      unsigned func:12;
      unsigned reserved:2;
      unsigned scheme:2;
    } revision;
  } off0x00;

  u4 off0x04;
  u4 off0x08;
  u4 off0x0c;

  struct
  {
    struct
    {
      unsigned autoidle:1;
      unsigned softreset:1;
      unsigned enawakeup:1;
      unsigned idlemode:2;
      unsigned reserved:27;
    } sysconfig;
  } off0x10;
  
  u4 off0x14;
  u4 off0x18;
  u4 off0x1c;

  struct
  {
    struct
    {
      unsigned dmaevent_ack:1;
      unsigned reserved:31;
    } eoi;
  } off0x20;

  struct
  {
    struct u4bits_t irqstatus_raw_0;
  } off0x24;
  struct
  {
    struct u4bits_t irqstatus_raw_1;
  } off0x28;
  struct
  {
    struct u4bits_t irqstatus_0;
  } off0x2c;
  struct
  {
    struct u4bits_t irqstatus_1;
  } off0x30;
  struct
  {
    struct u4bits_t irqstatus_set_0;
  } off0x34;
  struct
  {
    struct u4bits_t irqstatus_set_1;
  } off0x38;
  struct
  {
    struct u4bits_t irqstatus_clr_0;
  } off0x3c;
  struct
  {
    struct u4bits_t irqstatus_clr_1;
  } off0x40;
  struct
  {
    struct u4bits_t irqwaken_0;
  } off0x44;
  struct
  {
    struct u4bits_t irqwaken_1;
  } off0x48;
  
  u4 off0x4c;

  u4 off0x50;
  u4 off0x54;
  u4 off0x58;
  u4 off0x5c;

  u4 off0x60;
  u4 off0x64;
  u4 off0x68;
  u4 off0x6c;

  u4 off0x70;
  u4 off0x74;
  
  struct
  { 
    unsigned resetdone:1;
    unsigned reserved:31;
  } sysstatus;
  u4 reserved3[6];
  struct 
  {
    unsigned disablemodule:1;
    unsigned gatingratio:1;
    unsigned reserved:29;
  } ctrl;
  union u4bits_t oe;
  union u4bits_t datain;
  union u4bits_t dataout;
  union u4bits_t leveldectect0;
  union u4bits_t leveldectect1;
  union u4bits_t risingdectect;
  union u4bits_t fallingdetect;
  union u4bits_t debouncenable;
  struct
  {
    unsigned debouncetime:8;
    unsigned reserved:24;
  } debouncetime;
  u4 reserved4[14];
  union u4bits_t cleardataout;
  union u4bits_t setdataout;
};

struct u2lsb_t 
{
  u1 value;
  u1 reserved;
};

struct uart_t
{
  union 
  {
    u4 reserved;
    struct u2lsb_t thr;
    struct u2lsb_t rhr;
    struct u2lsb_t clock_lsb;
  } off0x00;

  union
  {
    u4 reserved;
    struct 
    {
      unsigned rhrit:1;
      unsigned thrit:1;
      unsigned lastrxbyteit:1;
      unsigned rxoverrunit:1;
      unsigned stsfifotrigit:1;
      unsigned txstatusit:1;
      unsigned linestsit:1;
      unsigned eofit:1;
      unsigned reserved:8;
    } ier_irda;
    struct
    {
      unsigned rhrit:1;
      unsigned thrit:1;
      unsigned rxstopit:1;
      unsigned rxoverrunit:1;
      unsigned reserved0:1;
      unsigned txstatusit:1;
      unsigned reserved:9;
    } ier_cir;
    struct
    {
      unsigned rhrit:1;
      unsigned thrit:1;
      unsigned linestsit:1;
      unsigned modemstsit:1;
      unsigned sleepmode:1;
      unsigned xoffit:1;
      unsigned rtsit:1;
      unsigned ctsit:1;
      unsigned reserved:8;
    } ier_uart;
    struct
    {
      unsigned clock_msb:5;
      unsigned reserved:11;
    } dlh;
  } off0x04;

  union
  {
    u4 reserved;
    struct
    {
      unsigned swflowcontrol:4;
      unsigned enhanceden:1;
      unsigned specialchardectect:1;
      unsigned autortsen:1;
      unsigned autoctsen:1;
      unsigned reserved:8;
    } efr;
    struct
    {
      unsigned it_pending:1;
      unsigned it_type:5;
      unsigned fcr_mirror:2;
      unsigned reserved:8;
    } iir_uart;
    struct
    { 
      unsigned rhrit:1;
      unsigned thrit:1;
      unsigned rxoeit:1;
      unsigned reserved0:1;
      unsigned txstatusit:1;
      unsigned reserved1:10;
    } iir_cir;
    struct
    {
      unsigned fifo_en:1;
      unsigned rx_fifo_clear:1;
      unsigned tx_fifo_clear:1;
      unsigned dma_mode:1;
      unsigned tx_fifo_trig:2;
      unsigned rx_fifo_trig:2;
      unsigned reserved:8;
    } fcr;
    struct
    {
      unsigned rhrit:1;
      unsigned thrit:1;
      unsigned rx_fifo_last_byte_it:1;
      unsigned rx_oe_it:1;
      unsigned sts_fifo_it:1;
      unsigned tx_status_it:1;
      unsigned line_sts_it:1;
      unsigned eof_it:1;
      unsigned reserved:8;
    } iir_irda;
  } off0x08;
 
  union
  {
    u4 reserved;
    struct
    {
      unsigned char_length:2;
      unsigned nb_stop:1;
      unsigned parity_en:1;
      unsigned parity_type1:1;
      unsigned parity_type2:1;
      unsigned break_en:1;
      unsigned div_en:1;
      unsigned reserved:8;
    } lcr;
  } off0x0c;
  
  union
  {
    u4 reserved;
    struct
    {
      unsigned dtr:1;
      unsigned rts:1;
      unsigned ristsch:1;
      unsigned cdstsch:1;
      unsigned loopbacken:1;
      unsigned xonen:1;
      unsigned tcrtlr:1;
      unsigned reserved:9;
    } mcr;
    struct 
    {
      u1 xonword1:8;
      u1 reserved:8;
    } xon1_addr1;
  } off0x10;

  union
  {
    u4 reserved;
    struct
    {
      u1 xonword2:8;
      u1 reserved:8;
    } xon2_addr2;
    struct
    {
      unsigned rxfifoe:1;
      unsigned reserved0:4;
      unsigned rxstop:1;
      unsigned reserved1:1;
      unsigned thrempty:1;
      unsigned reserved2:8;
    } lsr_cir;
    struct 
    {
      unsigned rx_fifo_e:1;
      unsigned sts_fifo_e:1;
      unsigned crc:1;
      unsigned abort:1;
      unsigned frame_too_long:1;
      unsigned rx_last_byte:1;
      unsigned sts_fifo_full:1;
      unsigned thr_empty:1;
      unsigned reserved:8;
    } lsr_irda;
    struct
    {
      unsigned rxfifoe:1;
      unsigned rxoe:1;
      unsigned rxpe:1;
      unsigned rxfe:1;
      unsigned rxbi:1;
      unsigned txfifoe:1;
      unsigned txsre:1;
      unsigned rxfifosts:1;
      unsigned reserved:8;
    } lsr_uart;
  } off0x14;

  union 
  {
    u4 reserved;
    struct
    {
      unsigned rxfifotrighalt:4;
      unsigned rxfifotrigstart:4;
      unsigned reserved:8;
    } tcr;
    struct
    {
      unsigned cts_sts:1;
      unsigned dsr_sts:1;
      unsigned dcd_sts:1;
      unsigned ncts_sts:1;
      unsigned ndsr_sts:1;
      unsigned nri_sts:1;
      unsigned ncd_sts:1;
      unsigned reserved:8;
    } msr;
    struct
    {
      u1 xoffword1;
      u1 reserved;
    } xoff1;
  } off0x18;

  union
  {
    u4 reserved;
    struct
    {
      u1 spr_word;
      u1 reserved;
    } spr;
    struct
    {
      unsigned tx_fifo_trig_dma:4;
      unsigned rx_fifo_trig_dma:4;
      unsigned reserved:8;
    } tlr;
    struct
    {
      u1 xoffword2;
      u1 reserved;
    } xoff2;
  } off0x1c;

  union 
  {
    u4 reserved;
    struct
    {
      unsigned modeselect:3;
      unsigned irsleep:1;
      unsigned settxir:1;
      unsigned sct:1;
      unsigned sipmode:1;
      unsigned frameendmode:1;
      unsigned reserved:8;
    } mdr1;
  } off0x20;

  union
  {
    u4 reserved;
    struct
    {
      unsigned irtxunderrun:1;
      unsigned stsfifotrig:2;
      unsigned uartpulse:1;
      unsigned cirpulsemode:2;
      unsigned irrxinvert:1;
      unsigned settxiralt:1;
      unsigned reserved:8;
    } mdr2;
  } off0x24;

  union
  {
    u4 reserved;
    struct
    {
      u1 txfll;
      u1 reserved;
    } txfll;
    struct
    {
      unsigned reserved0:1;
      unsigned crc_error:1;
      unsigned abort_detect:1;
      unsigned frame_too_long_error:1;
      unsigned oe_error:1;
      unsigned reserved1:11;
    } sflsr;
  } off0x28;

  union 
  {
    u4 reserved;
    struct
    {
      u1 resume;
      u1 reserved;
    } resume;
    struct
    {
      unsigned txflh:5;
      unsigned reserved:11;
    } txflh;
  } off0x2c;

  union
  {
    u4 reserved;
    struct
    {
      u1 rxfll;
      u1 reserved;
    } rxfll;
    struct
    {
      u1 sfregl;
      u1 reserved;
    } sfregl;
  } off0x30;

  union
  {
    u4 reserved;
    struct 
    {
      u1 sfregh;
      u1 reserved;
    } sfregh;
    struct
    {
      u1 rxflh;
      u1 reserve;
    } rxflh;
  } off0x34;

  union
  {
    u4 reserved;
    struct
    {
      unsigned reserved0:6;
      unsigned xboftype:1;
      unsigned stsfiforeset:1;
      unsigned reserved1:8;
    } blr;
    struct
    {
      unsigned speed:5;
      unsigned bitbychar:1;
      unsigned paritytype:2;
      unsigned reserved:8;
    } uasr;
  } off0x38;

  union
  {
    u4 reserved;
    struct
    {
      unsigned eoten:1;
      unsigned aborten:1;
      unsigned sctxen:1;
      unsigned sendsip:1
      unsigned distxunderrun:1;
      unsigned disirrx:1;
      unsigned sdmod:1
      unsigned pulsetype:1;
      unsigned reserved:8;
    } acreg;
  } off0x3c;
  
  union
  {
    u4 reserved;
    struct
    {
      unsigned dmamodectl:1;
      unsigned dmamode2:2;
      unsigned txemptyctlit:1;
      unsigned rxctsdsrwakeupenable:1;
      unsigned dsrit:1;
      unsigned txtriggranu1:1;
      unsigned rxtriggranu1:1;
      unsigned reserved:8;
    } scr;
  } off0x40;

  union
  {
    u4 reserved;
    struct
    {
      unsigned txfifofull:1;
      unsigned rxctsdsrwakeupsts:1
      unsigned dmacounterrst:1;
      unsigned reserved:13;
    } ssr;
  } off0x44;

  union
  {
    u4 reserved;
    struct
    {
      u1 eblr;
      u1 reserved;
    } eblr;
  } off0x48;

  u4 off0x4c;

  union
  {
    u4 reserved;
    struct
    {
      unsigned minorrev:4;
      unsigned majorrev:4;
      unsigned reserved:8;
    } mvr;
  } off0x50;

  union
  {
    u4 reserved;
    struct
    {
      unsigned autoidle:1;
      unsigned softreset:1;
      unsigned enawakeup:1;
      unsigned idlemode:2;
      unsigned reserved:10;
    } sysc;
  } off0x54;

  union
  {
    u4 reserved;
    struct
    {
      unsigned resetdone:1;
      unsigned reserved:15;
    } syss;
  } off0x58;

  union 
  {
    u4 reserved;
    struct
    {
      unsigned cts_activity:1;
      unsigned dsr_activity:1;
      unsigned ri_activity:1;
      unsigned dcd_activity:1;
      unsigned rx_activity:1;
      unsigned rhr_interrupt:1;
      unsigned rls_interrupt:1;
      unsigned txwakeupen:1;
      unsigned reserved;
    } wer;
  } off0x5c;
  
  union 
  {
    u4 reserved;
    struct
    {
      u1 cfps;
      u1 reserved;
    } cfps;
  } off0x60;

  union
  {
    u4 reserved;
    struct
    {
      u1 rxfifo_lvl;
      u1 reserved;
    } rxfifo_lvl;
  } off0x64;

  union
  {
    u4 reserved;
    struct
    {
      u1 txfifo_lvl;
      u1 reserved;
    } txfifo_lvl;
  } off0x68;

  union
  {
    u4 reserved;
    struct
    {
      unsigned en_rxfifo_empty:1;
      unsigned en_txfifo_empty:1;
      unsigned reserved:14;
    } ier2;
  } off0x6c;

  union
  {
    u4 reserved;
    struct
    {
      unsigned rxfifo_empty_sts:1;
      unsigned txfifo_empty_sts:1;
      unsigned reserved:14;
    } isr2;
  } off0x70;

  union
  {
    u4 reserved;
    struct
    {
      u1 freq_sel;
      u1 reserved;
    } freq_sel;
  } off0x74;

  u4 off0x78;
  u4 off0x7c;
  
  union
  {
    u4 reserved;
    struct
    {
      unsigned disable_cir_rx_demod:1;
      unsigned nondefault_freq:1;
      unsigned set_dma_tx_threshold:1;
      unsigned reserved:13;
    } mdr3;
  } off0x80;

  union
  {
    u4 reserved;
    struct
    {
      unsigned tx_dma_threshold:6;
      unsigned reserved:10;
    } tx_dma_threshold;
  } off0x84;

};

volatile struct gpio_t gpio1 __attribute__ ((section(".gpio1")));
volatile struct uart_t uart0 __attribute__ ((section(".uart0")));


main()
{
  gpio1.setdataout.bits.b21 = 1;
} 
