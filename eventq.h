/* Name: eventq.h */
/* Description: */
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
#ifndef EVENTQ_H
#define EVENTQ_H

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define EVENTQ_SIZE 64

typedef struct eventq_s eventq_t;

typedef enum {
    EVENTQ_SUCCESS = 0,
    EVENTQ_FAILURE,
    EVENTQ_EMTPY_QUEUE,  /* queue capacity is zero (i.e. zero items in the queue) */
    EVENTQ_FULL_QUEUE,   /* queue capacity is EVENTQ_SIZE (i.e. EVENTQ_SIZE items in the queue) */
} eventq_status_t;

typedef enum {
    EVENT_NULL = 0,
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
} event_t;

struct eventq_s {
    uint8_t size;      /* size of the queue (i.e. maximum number of items in the queue) */
    uint8_t capacity;  /* the number of items in the queue */
    event_t* queue;    /* an array to contain the event items */
};

eventq_status_t eventq_init(eventq_t* self, event_t* queue, uint8_t size);
eventq_status_t eventq_flush(eventq_t* self);
eventq_status_t eventq_enqueue(eventq_t* self, event_t event);
eventq_status_t eventq_dequeue(eventq_t* self, event_t* event);
eventq_status_t eventq_get_capacity(eventq_t* self, uint8_t* capacity);

#ifdef __cplusplus
}  /* End of CPP guard */
#endif

#endif  /* EVENTQ_H */
