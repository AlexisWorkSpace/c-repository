void main(void) {
    uint8_t valor = 0xFF; // 0b11111111
    uint8_t mascara;

    for (uint8_t i = 0; i < 6; i++) {
        mascara = ~(1 << i);     
        valor = 0xFF & mascara;  
        PORTB = valor;
        __delay_ms(500); 
    }

    while (1);
}
