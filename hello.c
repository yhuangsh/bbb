typedef unsigned int u4;

union u4bits_t
{
  u4 theu4;
  struct 
  {
    unsigned b31:1;
    unsigned b30:1;
    unsigned b29:1;
    unsigned b28:1;
    unsigned b27:1;
    unsigned b26:1;
    unsigned b25:1;
    unsigned b24:1;
    unsigned b23:1;
    unsigned b22:1;
    unsigned b21:1;
    unsigned b20:1;
    unsigned b19:1;
    unsigned b18:1;
    unsigned b17:1;
    unsigned b16:1;
    unsigned b15:1;
    unsigned b14:1;
    unsigned b13:1; 
    unsigned b12:1;
    unsigned b11:1;
    unsigned b10:1;
    unsigned b9:1;
    unsigned b8:1;
    unsigned b7:1;
    unsigned b6:1;
    unsigned b5:1;
    unsigned b4:1;
    unsigned b3:1;
    unsigned b2:1;
    unsigned b1:1;
    unsigned b0:1;
  } bits;
};
    
struct gpio_t 
{
  struct 
  {
    unsigned scheme:2;
    unsigned reserved:2;
    unsigned func:12;
    unsigned rtl:5;
    unsigned major:3;
    unsigned custom:2;
    unsigned minor:6;
  } revision;
  u4 reserved0[3];
  struct 
  {
    unsigned reserved:27;
    unsigned idlemode:2;
    unsigned enawakeup:1;
    unsigned softreset:1;
    unsigned autoidle:1;
  } sysconfig;
  u4 reserved1[3];
  struct
  {
    unsigned reserved:31;
    unsigned dmaevent_ack:1;
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
    unsigned reserved:31;
    unsigned resetdone:1;
  } sysstatus;
  u4 reserved3[6];
  struct 
  {
    unsigned reserved:29;
    unsigned gatingratio:1;
    unsigned disablemodule:1;
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
    unsigned reserved:24;
    unsigned debouncetime:8;
  } debouncetime;
  u4 reserved4[14];
  union u4bits_t cleardataout;
  union u4bits_t setdataout;
};

volatile struct gpio_t gpio1 __attribute__ ((section(".gpio1")));

main()
{
  gpio1.setdataout.bits.b21 = 1;
} 