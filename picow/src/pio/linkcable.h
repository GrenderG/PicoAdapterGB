#pragma once

#include "hardware/pio.h"

#define LINKCABLE_PIO       pio0
#define LINKCABLE_SM        0

#define LINKCABLE_BITS       8
#define LINKCABLE_16BITS      16
#define LINKCABLE_32BITS      32

#define CABLE_PINS_START    0

static inline uint8_t linkcable_receive(void) {
    return pio_sm_get(LINKCABLE_PIO, LINKCABLE_SM);
}

static inline void linkcable_send(uint8_t data) {
    pio_sm_put(LINKCABLE_PIO, LINKCABLE_SM, data);
}

void linkcable_changeBits(void);
void linkcable_reset(void);
void linkcable_init(irq_handler_t onReceive, uint8_t BitsNum);