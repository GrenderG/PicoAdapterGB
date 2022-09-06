#ifndef FLASH_EEPROM_H
#define FLASH_EEPROM_H


//Flash reprograming example https://github.com/raspberrypi/pico-examples/blob/master/flash/program/flash_program.c
//https://www.makermatrix.com/blog/read-and-write-data-with-the-pi-pico-onboard-flash/

#define FLASH_DATA_WRITE (FLASH_PAGE_SIZE * 2)
#define FLASH_TARGET_OFFSET (FLASH_DATA_WRITE * 1024)
const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

//256 bytes for the Mobile Adapter GB config and 256 bytes to WiFi Config and other stuffs
unsigned char dummy_config[FLASH_DATA_WRITE] = {
    // Mobile Adapter GB config
    0x4D, 0x41, 0x01, 0x00, 0xD2, 0xC4, 0x03, 0xB7, 0xD2, 0x8D, 0x70, 0xA3,	0x67, 0x39, 0x38, 0x37,
    0x32, 0x37, 0x38, 0x31, 0x38, 0x33, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7A, 0x65, 0x6E, 0x61,
    0x72, 0x6F, 0x72, 0x39, 0x40, 0x73, 0x72, 0x76, 0x31, 0x2E, 0x64, 0x69,	0x6F, 0x6E, 0x2E, 0x6E,
    0x65, 0x2E, 0x6A, 0x70, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x6D, 0x61, 0x69, 0x6C, 0x2E, 0x73,
    0x72, 0x76, 0x31, 0x2E,	0x64, 0x69, 0x6F, 0x6E, 0x2E, 0x6E, 0x65, 0x2E, 0x6A, 0x70, 0x70, 0x6F,
    0x70, 0x2E, 0x73, 0x72, 0x76, 0x31, 0x2E, 0x64, 0x69, 0x6F, 0x6E, 0x2E,	0x6E, 0x65, 0x2E, 0x6A,
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA9, 0x67,	0x7F, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x44, 0x49,
    0x4F, 0x4E, 0x20, 0x50,	0x44, 0x43, 0x2F, 0x43, 0x44, 0x4D, 0x41, 0x4F, 0x4E, 0x45, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x62,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    //WiFi Config and other stuffs
	0x57, 0x69, 0x46, 0x69, 0x5F, 0x4E, 0x65, 0x74, 0x77, 0x6F, 0x72, 0x6B,	0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x50, 0x40, 0x24, 0x24,	0x77, 0x30, 0x72, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void print_buf(const uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", buf[i]);
        if (i % 16 == 15)
            printf("\n");
        else
            printf(" ");
    }
}

void ReadFlashConfig(){
    printf("Reading the target region:\n");
    print_buf(flash_target_contents, FLASH_DATA_WRITE);
}

void SaveFlashConfig(){    
    printf("\nProgramming target region...\n");
    flash_range_program(FLASH_TARGET_OFFSET, dummy_config, FLASH_DATA_WRITE);

    printf("Done. Read back target region:\n");
    print_buf(flash_target_contents, FLASH_DATA_WRITE);
}

void FormatFlashConfig(){
    printf("\nErasing target region...\n");
    flash_range_erase(FLASH_TARGET_OFFSET, FLASH_SECTOR_SIZE);

    printf("Done. Read back target region:\n");
    print_buf(flash_target_contents, FLASH_DATA_WRITE);
}

#endif