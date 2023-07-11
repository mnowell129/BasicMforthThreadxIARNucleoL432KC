#include "SelectIO.h"
#include "gpiointerface.h"
#include "rtos.h"

   GPIO_CLOCK_ENABLE(HOST_TX);
   GPIO_CLOCK_ENABLE(HOST_RX);
   GPIO_INIT_AS_ALTERNATE(HOST_TX);
   GPIO_INIT_AS_ALTERNATE(HOST_RX);

   GPIO_CLOCK_ENABLE(GREEN_LED);
   GPIO_INIT_AS_IN(HOST_GREEN);
   GPIO_INIT_AS_OUT(GREEN_LED);

   SETACTIVE(GREEN_LED);
   SETINACTIVE(GREEN_LED);

   SETHIGH(GREEN_LED);
   SETLOW(GREEN_LED);

RTOS_SEMA_OBJECT_STATIC(USARTRXSEMA);
   
#define USARTRXSEMA                    usart2ReceiveTaskSyncSemaphore
#define usart2ReceiveTaskSyncSemaphore_NAME       "usart2Rx"

   SEMA_CREATE_COUNTING_LITERAL(USARTRXSEMA,RECEIVE_BUFFER_SIZE,0);
