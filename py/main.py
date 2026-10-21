'''
Una empresa se dedica a la fabricación y recarga de matafuegos. La empresa dispone de N matafuegos que se
clasifican según el tipo de fuego que se puede apagar en ( A B C D K). Los códigos de los matafuegos son
números correlativos a partir de 2000.
Se debe ingresar primeramente, mediante una función según el código del matafuego, a que tipo pertenece y su
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

from funcs import *

CODIGO_INICIAL = 2000
TIPOS = ("A", "B", "C", "D", "K")
OPERACIONES = ("R", "N")
PORC_RECARGA = 0.40


def main():
    n = validar_entero("Cantidad de matafuegos (N): ", 1)
    tipos, costos = cargar_matafuegos(n, CODIGO_INICIAL, TIPOS)

    nuevos = [0] * n
    recargas = [0] * n
    recaudacion_total = 0.0
    recaudacion_recarga = 0.0

    print("\n=== Ingreso de remitos (nro de remito <= 0 para terminar) ===")
    remito = validar_entero("Nro de remito: ", 1, permitir_corte=True)
    while remito > 0:
        codigo = validar_entero("  Código del matafuego: ", CODIGO_INICIAL, CODIGO_INICIAL + n - 1)
        operacion = validar_opcion("  Operación (R=Recarga, N=Nuevo): ", OPERACIONES)
        cantidad = validar_entero("  Cantidad pedida: ", 1)

        i = codigo - CODIGO_INICIAL
        es_recarga = operacion == "R"
        importe = calcular_importe(costos[i], cantidad, es_recarga, PORC_RECARGA)
        recaudacion_total += importe
        if es_recarga:
            recargas[i] += cantidad
            recaudacion_recarga += importe
        else:
            nuevos[i] += cantidad

        remito = validar_entero("Nro de remito: ", 1, permitir_corte=True)

    # a)
    informe_por_tipos(tipos, nuevos, recargas, CODIGO_INICIAL, ("A", "B"))
    # b)
    print(f"\nPorcentaje de recaudación por recarga: "
          f"{porcentaje(recaudacion_recarga, recaudacion_total):.2f}%")
    # c)
    informe_no_pedidos(tipos, nuevos, CODIGO_INICIAL)


if __name__ == "__main__":
    main()
