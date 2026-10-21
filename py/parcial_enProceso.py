'''
Una empresa se dedica a la fabricación y recarga de matafuegos. La empresa dispone de N matafuegos que se
clasifican según el tipo de fuego que se puede apagar en ( A B C D K). Los códigos de los matafuegos son
números correlativos a partir de 2000.
Se debe ingresar primeramente, mediante una función según, el código del matafuego, a que tipo pertenece y su
respectivo costo unitario.
Luego, cada vez que se realiza un pedido, se dispone de la siguiente información:
 Nro de remito
 Código del matafuego (2000 a...)
 Tipo de Operación (R (Recarga) o N (Nuevo))
 Cantidad pedida
Esta información termina con Nro. de remito negativo o cero.
Cada remito siempre corresponde al mismo código de matafuego. La recarga es el 40% de uno nuevo.
Validar mediante funciones genéricas (con parámetros) cada dato ingresado, reutilizando la función si
corresponde.
Con las informaciones anteriores, realizar e informar el siguiente resumen:
a-) Listado indicando (SOLO PARA TIPO A y B):
Código del matafuego Cantidad de nuevos pedidos Cantidad de recargas pedidas
Implementar una función para el informe
b-) Porcentaje de recaudación por recarga respecto a la recaudación total de pedidos. Implementar función
Porcentaje
c-) Indicar los Códigos de los matafuegos y su respectivo tipo de aquellos que no fueron pedidos (nuevos).
Si todos fueron medidos, indicar el mensaje “TODOS FUERON PEDIDOS “
d-) Implementar función main
'''

'''
tipos de datos: 
char: caracteres (a, b, c, A, B, 1, 3, ?)
int: numeros enteros
float: numeros con coma
booleanos: verdadero, falso 
'''

TIPO_VALIDOS = ("A", "B", "C", "D", "K")

def main():
    n = int(input("[+] Cantidad de matafuegos (N): "))

    recaudacionTotal = 0.0
    recaudacionRecarga = 0.0
    nuevos = [0] * n
    recargas = [0] * n

    tipos, costos = [0] * n, [0] * n
    for i in range(n):
        '''
        tipos.append(input("[+] ingrese el tipo de matafuego: ").upper().strip())
        costos.append(float(input("[+] ingrese el costo unitario: ")))
        '''
        tipos[i] = input("[+] ingrese el tipo de matafuego: ")
        costos[i] = float(input("[+] ingrese el costo unitario: "))

    remito = int(input("[+] Nro de remito: "))
    while remito > 0:
        codigo = int(input("[+] Código del matafuego (mayor a 2000): "))
        operacion = input("[+] Operación (R=Recarga, N=Nuevo): ")
        cantidad = int(input("[+] Cantidad pedida: "))

        i = codigo - 2000
        esRecarga = operacion == "R"
        importe = costos[i] * cantidad
        if esRecarga:
            importe *= 0.40
            recargas[i] += cantidad
            recaudacionRecarga += importe
        recaudacionTotal += importe

        remito = int(input("[+] Nro de remito: "))

    

if __name__ == "__main__":
    main()
