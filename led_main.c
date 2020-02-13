#define SRAM_END 0x20000FFF
#define STACK_TOP SRAM_END

#define NVIC_ISER 0xE000E100
#define RCC_APB2ENR 0x4002101C
#define TIM3_PSC 0x40000428
#define TIM3_ARR 0x4000042C
#define TIM3_DIER 0x4000040C
#define TIM3_CR1 0x40000400
#define RCC_AHBENR 0x40021014
#define TIM3_SR 0x40000410

#define BSRR 0x48000418  //gpio stuff
#define ODR 0x48000414 
#define MODER 0x48000400

void    interruption();
void	handler();
void	main();

unsigned long *vector_table[] __attribute__((section (".vector_table"))) = {
        (unsigned long *) STACK_TOP,
        (unsigned long *) main,
        (unsigned long *) handler,
        (unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) handler,
	(unsigned long *) interruption
};


void	interruption()
{
	if (*(unsigned long *)(ODR) << 1 == 0)
		*(unsigned long *)(BSRR) |= 0x8;
	else
		*(unsigned long *)(BSRR) |= 0x80000;
	*(unsigned long *)(TIM3_SR) = 0;
}

void	main()
{
	*(unsigned long *)(RCC_AHBENR) |= 0x40000;
	*(unsigned long *)(RCC_APB2ENR) |= 0x2;
	volatile unsigned long i = 0;
	i++;
	i++;
	*(unsigned long *)(MODER) |= 0x40;
        *(unsigned long *)(NVIC_ISER) |= 0x10000;
        *(unsigned long *)(TIM3_DIER) |= 0x2;
	*(unsigned long *)(TIM3_PSC) = 16000;
	*(unsigned long *)(TIM3_ARR) = 500;
	*(unsigned long *)(TIM3_CR1) |= 0x1;
	while (1);
}

void	handler()
{	
	for(int i=0; i<=8; i++){
		i=i;
	}
}

