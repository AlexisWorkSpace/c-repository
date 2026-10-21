# ---------- Validaciones genéricas ----------
def validar_entero(mensaje, minimo, maximo=None, permitir_corte=False):
    """Pide un entero entre minimo y maximo (maximo opcional) hasta que sea válido.
    Si permitir_corte es True, también acepta cualquier valor <= 0 (fin de carga)."""
    while True:
        try:
            valor = int(input(mensaje))
        except ValueError:
            print("  Error: debe ingresar un número entero.")
            continue
        if permitir_corte and valor <= 0:
            return valor
        if valor < minimo or (maximo is not None and valor > maximo):
            rango = f">= {minimo}" if maximo is None else f"entre {minimo} y {maximo}"
            print(f"  Error: el valor debe estar {rango}.")
            continue
        return valor


def validar_real_positivo(mensaje):
    """Pide un número real mayor que 0."""
    while True:
        try:
            valor = float(input(mensaje))
        except ValueError:
            print("  Error: debe ingresar un número.")
            continue
        if valor <= 0:
            print("  Error: el valor debe ser mayor que 0.")
            continue
        return valor


def validar_opcion(mensaje, opciones):
    """Pide un texto que pertenezca a 'opciones' (sin distinguir mayúsculas)."""
    while True:
        valor = input(mensaje).strip().upper()
        if valor in opciones:
            return valor
        print(f"  Error: opción inválida. Opciones: {', '.join(opciones)}.")


# ---------- Carga y cálculos ----------
def cargar_matafuegos(cantidad, codigo_inicial, tipos_validos):
    """Pide tipo y costo unitario de 'cantidad' matafuegos correlativos desde
    codigo_inicial. Devuelve (tipos, costos); el índice es codigo - codigo_inicial."""
    tipos, costos = [], []
    for i in range(cantidad):
        print(f"\nMatafuego código {codigo_inicial + i}")
        tipos.append(validar_opcion(f"  Tipo ({', '.join(tipos_validos)}): ", tipos_validos))
        costos.append(validar_real_positivo("  Costo unitario: "))
    return tipos, costos


def calcular_importe(costo_unitario, cantidad, es_recarga, porc_recarga):
    """Importe de un pedido. Si es recarga, se cobra porc_recarga (0 a 1) del costo."""
    importe = costo_unitario * cantidad
    return importe * porc_recarga if es_recarga else importe


def porcentaje(parte, total):
    """Porcentaje de 'parte' respecto de 'total' (0 si total es 0)."""
    return parte * 100 / total if total > 0 else 0


# ---------- Informes ----------
def informe_por_tipos(tipos, nuevos, recargas, codigo_inicial, tipos_a_listar):
    """Lista código, nuevos y recargas solo de los matafuegos cuyo tipo esté en tipos_a_listar."""
    print(f"\n--- Matafuegos tipo {', '.join(tipos_a_listar)} ---")
    print(f"{'Código':<10}{'Nuevos pedidos':<18}{'Recargas pedidas':<18}")
    for i, tipo in enumerate(tipos):
        if tipo in tipos_a_listar:
            print(f"{codigo_inicial + i:<10}{nuevos[i]:<18}{recargas[i]:<18}")


def informe_no_pedidos(tipos, cantidades, codigo_inicial):
    """Muestra código y tipo de los elementos con cantidad 0, o un mensaje si no hay."""
    print("\n--- Matafuegos que no fueron pedidos (nuevos) ---")
    hay = False
    for i, tipo in enumerate(tipos):
        if cantidades[i] == 0:
            print(f"Código {codigo_inicial + i} - Tipo {tipo}")
            hay = True
    if not hay:
        print("TODOS FUERON PEDIDOS")
