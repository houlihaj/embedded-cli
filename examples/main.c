#include "cli.h"      // cli_t, cli_init
#include "cli_fns.h"  // cli_set_cmd_members

void user_uart_println(char* msg);

cli_t cli;

int main(void)
{
    cli.println = user_uart_println;
    cli_set_cmd_members(&cli);  // set the cli_t (i.e. cli) cmd_tbl and cmd_cnt members
    cli_init(&cli);

    // enable UART receive-data interrupts here, so that UART_Rx_IrqHandler() gets
    // called when data is received

    while (1)
    {
        // Must periodically call to process and execute received commands
        cli_process(&cli);
    }

    return 0;
}

/* For example.. */
void UART_Rx_IrqHandler()
{
    char c = UART->RxData;
    cli_put(&cli, c);
}

void user_uart_println(char* string)
{
    /* For example.. */
    HAL_UART_Transmit_IT(&huart, string, strlen(string));
}
