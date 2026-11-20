/* Name: main.c */
/* Description: An example to show eventq.c usage */
/* Author: John Houlihan */

/**
* MIT License
*
* Copyright (c) 2026 John Houlihan
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "eventq.h"
#include <stdio.h>


int main(int argc, char** argv)
{
    eventq_t eventq;          /* implement global eventq_t object */
    event_t app_event;        /*  */
    uint8_t eventq_capacity;  /*  */

    uint8_t app_event_queue_size = 64;
    event_t app_event_queue[app_event_queue_size];

    eventq_init(&eventq, app_event_queue, app_event_queue_size);

    eventq_enqueue(&eventq, EVENT_1);
    eventq_enqueue(&eventq, EVENT_3);

    eventq_dequeue(&eventq, &app_event);
    printf("Deque event :  %d\n", app_event);

    eventq_enqueue(&eventq, EVENT_2);
    eventq_enqueue(&eventq, EVENT_4);
    eventq_enqueue(&eventq, EVENT_1);

    eventq_get_capacity(&eventq, &eventq_capacity);
    printf("Event queue capacity :  %d\n", eventq_capacity);

    eventq_dequeue(&eventq, &app_event);
    printf("Deque event :  %d\n", app_event);
    eventq_dequeue(&eventq, &app_event);
    printf("Deque event :  %d\n", app_event);
    eventq_dequeue(&eventq, &app_event);
    printf("Deque event :  %d\n", app_event);
    eventq_dequeue(&eventq, &app_event);
    printf("Deque event :  %d\n", app_event);

    return 0;
}
