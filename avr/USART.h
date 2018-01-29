
/*
void uart_init();
void print_char( unsigned char data );
void print_num(int num);
void print_string(char* str);
void print_ulong();
 */

#define F_CPU 16000000UL

#define BAUD 9600
#define BAUD_PRESCALE (((F_CPU)/(16UL * BAUD))-1)

struct node
{
    unsigned char data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int item);
void dequeue();

ISR(USART_RXC_vect)
{

}

void print_char( unsigned char data )
{
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = data;
}

void print_num(int num)
{
	int numberArray[5];
	int c = 0;
	int n = num;
	/* extract each digit */
	while (n != 0)
	{
		numberArray[c] = n % 10;
		n /= 10;
		c++;
	}
	while(c>0)
	{
		print_char(numberArray[--c]+'0');
	}
}

void print_ulong(unsigned long long num)
{
	unsigned long long numberArray[10];
	int c = 0;
	unsigned long long n = num;
	/* extract each digit */
	while (n != 0)
	{
		numberArray[c] = n % 10;
		n /= 10;
		c++;
	}
	while(c>0)
	{
		print_char(numberArray[--c]+'0');
	}
}

void print_string(char* str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		print_char(str[i]);
	}
}

void uart_init()
{
	UBRRH = (BAUD_PRESCALE >> 8);
	UBRRL = BAUD_PRESCALE;
	UCSRB |= (1<<TXEN)|(1<<RXEN);
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\n\nqueue is empty \n");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("\n\n%d deleted", temp->data);
        free(temp);
    }
}

void enqueue(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = NULL;
    if (rear == NULL)
    {
        front = nptr;
        rear = nptr;
    }
    else
    {
        rear->next = nptr;
        rear = rear->next;
    }
}
