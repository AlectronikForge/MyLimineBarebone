#include <stdint.h>
#include <stddef.h>

extern void gdtLoad( void *ptr );

typedef struct {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t flags;
	uint8_t granulaity;
	uint8_t base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct  {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) gdtptr_t;

gdt_entry_t gdt[3] = {
    { 0,0,0,0,0,0 },
    { 0xFFFF, 0, 0, 0x9A, (1 << 5) | (1 << 7) | 0x0F, 0 },
    { 0xFFFF, 0, 0, 0x92, (1 << 5) | (1 << 7) | 0x0F, 0 }
};

gdtptr_t ptr = { sizeof(gdt)-1, (uint64_t)gdt };

void
load_gdt() {
    gdtLoad( &ptr );
}
