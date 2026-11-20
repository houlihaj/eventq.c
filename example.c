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
    event_t app_event;

    eventq_init();

    eventq_enqueue(EVENT_1);
    eventq_enqueue(EVENT_3);

    eventq_dequeue(&app_event);
    printf("Deque event :  %d\n", app_event);

    eventq_enqueue(EVENT_2);
    eventq_enqueue(EVENT_4);
    eventq_enqueue(EVENT_1);

    printf("Event queue capacity :  %d\n", eventq_get_capacity());

    eventq_dequeue(&app_event);
    printf("Deque event :  %d\n", app_event);
    eventq_dequeue(&app_event);
    printf("Deque event :  %d\n", app_event);
    eventq_dequeue(&app_event);
    printf("Deque event :  %d\n", app_event);
    eventq_dequeue(&app_event);
    printf("Deque event :  %d\n", app_event);

    return 0;
}
