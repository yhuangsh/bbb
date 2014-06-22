typedef unsigned char u1;
typedef unsigned int u4;

union u4bits_t
{
  u4 theu4;
  struct 
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
  } bits;
};
    
struct gpio_t 
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
  u4 reserved0[3];
  struct 
  {
    unsigned autoidle:1;
    unsigned softreset:1;
    unsigned enawakeup:1;
    unsigned idlemode:2;
    unsigned reserved:27;
  } sysconfig;
  u4 reserved1[3];
  struct
  {
    unsigned dmaevent_ack:1;
    unsigned reserved:31;
  } eoi;
  union u4bits_t irqstatus_raw_0;
  union u4bits_t irqstatus_raw_1;
  union u4bits_t irqstatus_0;
  union u4bits_t irqstatus_1;
  union u4bits_t irqstatus_set_0;
  union u4bits_t irqstatus_set_1;
  union u4bits_t irqstatus_clr_0;
  union u4bits_t irqstatus_clr_1;
  union u4bits_t irqwaken_0;
  union u4bits_t irqwaken_1;
  u4 reserved2[50];
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
  unsigned char value;
  unsigned char reserved;
};

struct uart_t
{
  union 
  {
    struct u2lsb_t thr;
    struct u2lsb_t rhr;
    struct u2lsb_t clock_lsb;
  } off0x00;
  u2 reserved0;
  union
  {
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
  u2 reserved1;
  union
  {
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
  
};

volatile struct gpio_t gpio1 __attribute__ ((section(".gpio1")));
volatile struct uart_t uart0 __attribute__ ((section(".uart0")));


main()
{
  gpio1.setdataout.bits.b21 = 1;
} 
