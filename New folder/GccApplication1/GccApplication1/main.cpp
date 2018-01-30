#define F_CPU 16000000UL

// include the library code:
#include "lcd.h"
#include "uart.h"
#include "io.h"

void mainmenu();
void  get_info();
int select_food();
void selected_food();
void change_food();

int main() {
	sei();
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
	// set up the LCD's number of columns and rows:
	// pinMode(13,OUTPUT);
	
	DDRB&= ~(1<<s_zero);
	DDRB&= ~(1<<s_one);
   DDRB&= ~(1<<s_two);


	lcd_init();
	mainmenu();
	// puts a message to the lcd_
	//  lcd_puts("hello, world!");
}



int select_food()
{
	wait_message();
	get_info();
	lcd_clear();
	lcd_puts("Food");

	lcd_setCursor(8,0);
	lcd_puts("Price");

	lcd_setCursor(14,0);
	lcd_puts("No");

	int selected_pk=0;
	lcd_setCursor(0,1);

	lcd_puts(food[selected_pk].name);

	lcd_setCursor(8,1);
	lcd_num(food[selected_pk].price);

	lcd_setCursor(14,1);
	lcd_num(food[selected_pk].num);


	while(1)
	{
		int in=input();

		if (in==up)
		{
			if (selected_pk==0)  selected_pk=num_of_food-1;
			else selected_pk--;
			select_food_print(selected_pk);

		}

		else if (in==down)
		{
			if (selected_pk==num_of_food-1) selected_pk=0;
			else selected_pk++;
			select_food_print(selected_pk);

		}

		else if (in==left)
		{
			if(food[selected_pk].num != 0)
			{
				food[selected_pk].num--;
				select_food_print(selected_pk);
			}


		}

		else if (in==right)
		{
			food[selected_pk].num++;
			select_food_print(selected_pk);

		}

		else if (in==del)
		{
			if (display_message1("Set the no to 0?"))
			food[selected_pk].num=0;

			lcd_clear();
			lcd_puts("Food");

			lcd_setCursor(8,0);
			lcd_puts("Price");

			lcd_setCursor(14,0);
			lcd_puts("No");

			select_food_print(selected_pk);
		}

		else if (in==ok)
		{
			if (display_message1("Save the changes"))
			{
				send_info();
				_delay_ms(DELAY_TIME);
				return 1;
			}

			lcd_clear();
			lcd_puts("Food");

			lcd_setCursor(8,0);
			lcd_puts("Price");

			lcd_setCursor(14,0);
			lcd_puts("No");

			select_food_print(selected_pk);

		}


		else if (in==back)
		{
			if (display_message1("Discard Changes?"))
			{
				_delay_ms(DELAY_TIME);
				return 0;
			}

			lcd_clear();
			lcd_puts("Food");

			lcd_setCursor(8,0);
			lcd_puts("Price");

			lcd_setCursor(14,0);
			lcd_puts("No");

			select_food_print(selected_pk);

		}




		_delay_ms(DELAY_TIME_ONE);
	}

}



void selected_food()
{
	wait_message();
	get_info();
	lcd_clear();

	int ar[100];
	int count=0;
	for (int i=0;i<num_of_food;i++)
	{
		if (food[i].num>0)
		{
			ar[count]=i;
			//    lcd_puts(ar[count]);
			count++;
		}
	}
	if (count==0)
	{
		lcd_puts("No Foods Ordered");
		lcd_setCursor(6,1);
		lcd_puts(">Ok");
		while(1)
		{
			int in=input();
			if (in == ok)
			{
				_delay_ms(DELAY_TIME);
				//mainmenu();
				return ;
			}
		}

	}
	lcd_puts("Food");

	lcd_setCursor(8,0);
	lcd_puts("Price");

	lcd_setCursor(14,0);
	lcd_puts("No");

	lcd_setCursor(0,1);

	int pk=0;

	lcd_puts(food[ar[pk]].name);

	lcd_setCursor(8,1);
	lcd_num(food[ar[pk]].price);

	lcd_setCursor(14,1);
	lcd_num(food[ar[pk]].num);


	while(1)
	{
		int in=input();

		if (in==up)
		{
			if (pk==0)  pk=count-1;
			else   pk--;
			select_food_print(ar[pk]);

		}

		else if (in==down)
		{
			if (pk==count-1) pk=0;
			else pk++;
			select_food_print(ar[pk]);

		}


		else if (in==ok || in==back)
		{
			return;
		}

		_delay_ms(DELAY_TIME_ONE);
	}
}






void mainmenu()
{
	lcd_clear();
	num_of_food=0;
	int state=0;
	int first_visit=0;
	main_menu_print(first_visit);

	while(1)
	{
		int in=input();
		//  lcd_puts (in);
		if (state==0&& (in==up ||in==down))
		{
			lcd_setCursor(0,0);
			lcd_puts(" ");
			lcd_setCursor(0,1);
			lcd_puts(">");
			state=1;
		}
		else if (state==1 && (in==up ||in==down))
		{
			lcd_setCursor(0,1);
			lcd_puts(" ");
			lcd_setCursor(0,0);
			lcd_puts(">");
			state=0;
		}
		else if (in==ok)
		{
			_delay_ms(DELAY_TIME);
			if (state==0)
			{
				int c=0;
				if (first_visit==0)
				c=select_food();
				else
				change_food();
				if (c==1)
				first_visit=1;
				state=0;
				main_menu_print(first_visit);
			}
			else
			//selected_food();
			{
				selected_food();
				main_menu_print(first_visit);
				state=0;
			}

		}
		_delay_ms(DELAY_TIME_ONE);
	}



}








void change_food()
{
	wait_message();
	get_info();
	lcd_clear();
	lcd_puts("Food");

	lcd_setCursor(8,0);
	lcd_puts("Price");

	lcd_setCursor(14,0);
	lcd_puts("No");

	int selected_pk=0;
	lcd_setCursor(0,1);

	lcd_puts(food[selected_pk].name);

	lcd_setCursor(8,1);
	lcd_num(food[selected_pk].price);

	lcd_setCursor(14,1);
	lcd_num(food[selected_pk].num);


	while(1)
	{
		int in=input();

		if (in==up)
		{
			if (selected_pk==0)  selected_pk=num_of_food-1;
			else selected_pk--;
			select_food_print(selected_pk);

		}

		else if (in==down)
		{
			if (selected_pk==num_of_food-1) selected_pk=0;
			else selected_pk++;
			select_food_print(selected_pk);

		}

		else if (in==left)
		{
			if (food[selected_pk].p==0)
			{
				if(food[selected_pk].num != 0)
				{
					food[selected_pk].num--;
					select_food_print(selected_pk);
				}

			}
			else
			{
				cannot_cancel();
				lcd_clear();
				lcd_puts("Food");

				lcd_setCursor(8,0);
				lcd_puts("Price");

				lcd_setCursor(14,0);
				lcd_puts("No");

				select_food_print(selected_pk);
			}
		}







		else if (in==right)
		{
			food[selected_pk].num++;
			select_food_print(selected_pk);

		}

		else if (in==del)
		{
			if (food[selected_pk].p==0)
			{
				if (display_message1("Set the no to 0?"))
				food[selected_pk].num=0;
			}
			else
			cannot_cancel();

			lcd_clear();
			lcd_puts("Food");

			lcd_setCursor(8,0);
			lcd_puts("Price");

			lcd_setCursor(14,0);
			lcd_puts("No");

			select_food_print(selected_pk);
		}

		else if (in==ok)
		{
			if (display_message1("Save the changes"))
			{
				send_info();
				_delay_ms(DELAY_TIME);
				return;
			}

			lcd_clear();
			lcd_puts("Food");

			lcd_setCursor(8,0);
			lcd_puts("Price");

			lcd_setCursor(14,0);
			lcd_puts("No");

			select_food_print(selected_pk);

		}


		else if (in==back)
		{
			if (display_message1("Discard Changes?"))
			{
				_delay_ms(DELAY_TIME);
				return ;
			}

			lcd_clear();
			lcd_puts("Food");

			lcd_setCursor(8,0);
			lcd_puts("Price");

			lcd_setCursor(14,0);
			lcd_puts("No");

			select_food_print(selected_pk);

		}




		_delay_ms(DELAY_TIME_ONE);
	}

}
