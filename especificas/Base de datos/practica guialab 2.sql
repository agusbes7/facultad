-- Inconsistencia de consulta hay pedidos sin fecha de envio pero con fecha de entrega
-- LISTA PEDIDOS NO ENVIADOS
SELECT * FROM main.pedido as p
WHERE   p.fecha_envio IS NULL;
-- ########################
-- LISTA DE PEDIDOS EN ESE PERIODO NO ENVIADOS
SELECT * FROM main.pedido as p
WHERE p.fecha_pedido BETWEEN '1996-04-30' AND '1996-06-01' AND p.fecha_envio IS NULL ;
-- ########################
--LISTA PRODUCTO con DISPONIBILIDAD QUE FIGURAN SUSPENDIDO
SELECT id_producto,nombre_producto,precio_unidad
FROM main.producto AS p
WHERE p.unidades_en_existencia > 0
  AND p.suspendido = true;
-- ########################
-- PRODUCTOS CON NOMBRE PARCIAL Y NOMBRE EXACTO
SELECT id_producto,nombre_producto FROM main.Producto AS p
WHERE  p.nombre_producto LIKE('Queso%');
SELECT * FROM main.producto AS p
WHERE p.nombre_producto LIKE('Queso Cabrales');
-- ###################################
-- EMPRESA DE ENVIO CON LA CATEGORIA DE PRODUCTO TRANSPORTADO
SELECT DISTINCT e.nombre_empresa, c.nombre_categoria FROM main.pedido as p
JOIN main.empresa_envio AS e  on(p.id_empresa_envio=e.id_empresa_envio)
JOIN main.detalle_pedido AS dp on(dp.id_pedido=p.id_pedido)
JOIN main.producto AS pr ON(pr.id_producto=dp.id_producto)
JOIN main.categoria AS c ON(c.id_categoria=pr.id_categoria)
-- ###################################
-- PEDIDO NO ENVIADOS CON FILTRO DE ORDEN
SELECT * FROM main.pedido as p
WHERE   p.fecha_envio IS NULL
ORDER BY p.fecha_pedido DESC;
-- ##################################
-- PEDIDOS ENVIADOS EN DETERMINADO PERIODO PARA RESIDENTES ALEMANES
SELECT p.id_pedido,p.fecha_envio,c.* FROM main.pedido AS p 
JOIN main.cliente AS c ON (p.id_cliente=c.id_cliente)
JOIN main.localidad AS l ON(l.id_localidad=c.id_localidad)
JOIN main.pais AS pa ON (pa.id_pais=l.id_pais)
WHERE pa.nombre='Alemania' AND (p.fecha_envio BETWEEN '1994-08-01' AND '1994-08-31')
ORDER BY p.fecha_envio DESC;
--#########################################
-- Obtengo las localidades de origen de los proveedores 
--Accedo a donde proveen productos que se hayan vendido en algun pedido
-- Accedo al cliente vinculado al pedido y obtengo su localidad
SELECT DISTINCT 
l.nombre as Local_proveedor ,
lo.nombre as Local_cliente
FROM main.proveedor AS p
JOIN main.localidad AS l ON (l.id_localidad=p.id_localidad)
JOIN main.producto AS pr ON(pr.id_proveedor=p.id_proveedor)
JOIN main.detalle_pedido  AS dp ON(dp.id_producto=pr.id_producto)
JOIN main.pedido  AS pe ON(pe.id_pedido=dp.id_pedido)
JOIN main.cliente AS c ON (c.id_cliente=pe.id_cliente)
JOIN main.localidad AS lo ON(lo.id_localidad=c.id_localidad)
WHERE l.nombre <> lo.nombre;
--#########################################
-- PEDIDOS ENVIADOS CON UNA EMPRESA EN PARTICULAR Y A CLIENTES CON CIERTO ID
SELECT * FROM main.pedido AS p
JOIN main.empresa_envio AS ee ON (ee.id_empresa_envio=p.id_empresa_envio)
WHERE (ee.nombre_empresa LIKE ('Federal Shipping') AND p.id_cliente LIKE ('WIL%'))
AND p.fecha_envio IS NOT NULL;
--#########################################
-- EMPLEADOS QUE VENDIERON A CLIENTES QUE VIVEN EN EL MISMO PAIS ORDENADO
SELECT DISTINCT e.nombre,e.apellido FROM main.pedido AS p
JOIN main.empleado AS e ON(e.id_empleado=p.id_empleado)
JOIN main.cliente AS c ON(c.id_cliente=p.id_cliente)
JOIN main.localidad AS L_cliente ON(L_cliente.id_localidad=c.id_localidad)
JOIN main.localidad AS L_empleado ON(L_empleado.id_localidad=e.id_localidad)
WHERE L_cliente.id_pais= L_empleado.id_pais 
ORDER BY e.apellido ASC;
-- ##########################################

(SELECT c.nombre_empresa AS nombre,
       c.direccion, c.telefono,
       cl.nombre AS localidad, cp.nombre AS pais, c.id_cliente AS identificador,
	   'cliente' as entidad
FROM main.cliente AS c
JOIN main.localidad AS cl      ON cl.id_localidad = c.id_localidad
JOIN main.pais AS cp      ON cp.id_pais = cl.id_pais)
UNION
(SELECT p.nombre_proveedor AS nombre,
       p.direccion,p.telefono,
       cl.nombre AS localidad, cp.nombre AS pais,        p.id_proveedor::VARCHAR AS identificador,
	   'proveedor' AS entidad
FROM main.proveedor AS p
JOIN main.localidad AS cl      ON cl.id_localidad = p.id_localidad
JOIN main.pais AS cp      ON cp.id_pais = cl.id_pais)
ORDER BY nombre ASC;
-- ######################################
--Enunciado ambiguo(considero que no tiene sentido la consulta si no los une un pedido de por medio a un cliente y un proveedor aunque no interactuen nunca)
SELECT  loc_prov.nombre AS Localidad_proveedor,loc_clie.nombre AS Localidad_cliente,pe.id_pedido FROM main.producto AS p
JOIN main.proveedor AS pr ON (pr.id_proveedor=p.id_proveedor)
JOIN main.localidad AS loc_prov ON (loc_prov.id_localidad=pr.id_localidad)
JOIN main.detalle_pedido AS dp ON (dp.id_producto=p.id_producto)
JOIN main.pedido AS pe on(dp.id_pedido=pe.id_pedido)
JOIN main.cliente AS c ON(c.id_cliente=pe.id_cliente)
JOIN main.localidad AS loc_clie ON (loc_clie.id_localidad=c.id_localidad)
WHERE  loc_prov.nombre <> loc_clie.nombre
-- ####################################################
SELECT DISTINCT loc.nombre AS Nombre, 'CLIENTE'  AS tipo FROM main.localidad AS Loc
JOIN main.cliente AS c ON(c.id_localidad=Loc.id_localidad)
WHERE NOT EXISTS ( 
SELECT * FROM main.proveedor AS pr
WHERE pr.id_localidad=Loc.id_localidad)
UNION
SELECT DISTINCT loc.nombre AS Nombre, 'PROVEEDOR'  AS tipo FROM main.localidad AS Loc
JOIN main.proveedor AS pr ON(pr.id_localidad=Loc.id_localidad)
WHERE NOT EXISTS ( 
SELECT * FROM main.cliente AS c
WHERE c.id_localidad=Loc.id_localidad)
--###################################
-- El select debe contener los mismos atributos para que opere sobre las mismas relacion o conjuntos resultantes
(SELECT DISTINCT pr.id_producto,pr.nombre_producto 
	FROM main.producto AS pr
JOIN main.detalle_pedido AS dp ON(dp.id_producto=pr.id_producto)
JOIN main.pedido AS p ON(p.id_pedido=dp.id_pedido)
		WHERE p.id_cliente='TORTU'
			
		EXCEPT
(SELECT DISTINCT pr.id_producto,pr.nombre_producto
	FROM main.producto AS pr
JOIN main.detalle_pedido AS dp ON(dp.id_producto=pr.id_producto)
JOIN main.pedido AS p ON(p.id_pedido=dp.id_pedido)
		WHERE p.id_cliente='LILAS')
	ORDER BY id_producto ASC)
-- ##################################################
-- Solo puede comparar 1 valor con 1 columna
SELECT DISTINCT pr.nombre_producto 
	FROM main.producto AS pr
JOIN main.detalle_pedido AS dp ON(dp.id_producto=pr.id_producto)
JOIN main.pedido AS p ON(p.id_pedido=dp.id_pedido)
		WHERE p.id_cliente='TORTU' 
		AND pr.nombre_producto NOT IN
(SELECT DISTINCT pr.nombre_producto
	FROM main.producto AS pr
JOIN main.detalle_pedido AS dp ON(dp.id_producto=pr.id_producto)
JOIN main.pedido AS p ON(p.id_pedido=dp.id_pedido)
		WHERE p.id_cliente='LILAS')
-- #############################################
	SELECT c.nombre_contacto, c.direccion,c.telefono  FROM main.cliente AS c
	JOIN main.localidad AS l ON(l.id_localidad=c.id_localidad)
	WHERE l.nombre='Buenos Aires'
	UNION
		(SELECT DISTINCT c.nombre_contacto, c.direccion,c.telefono FROM main.cliente AS c
		JOIN main.pedido AS p ON (c.id_cliente=p.id_cliente)
		JOIN main.detalle_pedido AS dp ON (dp.id_pedido=p.id_pedido)
		JOIN main.producto AS pr ON (pr.id_producto=dp.id_producto)
		JOIN main.categoria AS cat ON (cat.id_categoria=pr.id_categoria)
		WHERE cat.nombre_categoria='Condimentos'
		)
-- ############################################################
-- Los empleados son solo 9 nunca se cruzan ademas el diseño por codigo postal hace que las mismas localidades tengan diferente area
SELECT DISTINCT l.id_localidad,l.nombre FROM main.localidad AS l
JOIN main.empleado AS e ON (e.id_localidad=l.id_localidad)
JOIN main.cliente AS c ON (c.id_localidad=l.id_localidad)
JOIN main.proveedor AS pr ON (pr.id_localidad=l.id_localidad)
-- ############################################################
-- EMPLEADOS DE LONDES QUE NO HAN ATENDIDO GENTE DE BUENOS AIRES
SELECT DISTINCT e.id_empleado,e.apellido,e.nombre FROM main.empleado AS e
JOIN main.localidad AS loc_empleado ON(loc_empleado.id_localidad=e.id_localidad)
JOIN main.pedido AS p ON(p.id_empleado=e.id_empleado)
JOIN main.cliente AS c ON(c.id_cliente=p.id_cliente)
JOIN main.localidad AS loc_cliente ON(loc_cliente.id_localidad=c.id_localidad)
WHERE   loc_cliente.nombre<>'Buenos Aires' AND loc_empleado.nombre='Londres'

-- ############################################################
-- PRODUCTOS CUYO PRECIO UNITARIO ES MAYOR QUE ALGUNO DE TODOS LOS PRECIOS DE PRODUCTOS CATEGORIA 3
SELECT  DISTINCT pr.id_producto,pr.nombre_producto,pr.precio_unidad,pr.id_categoria
FROM main.producto AS pr
WHERE pr.precio_unidad > SOME (
SELECT pr.precio_unidad FROM main.producto AS pr
WHERE pr.id_categoria=3)
ORDER BY precio_unidad
-- ############################################################
-- PRODUCTOS CUYO PRECIO UNITARIO ES IGUAL A ALGUNOD DE LOS PRECIOS DE PRODUCTOS CATEGORIA 3
SELECT  DISTINCT pr.id_producto,pr.nombre_producto,pr.precio_unidad,pr.id_categoria
FROM main.producto AS pr
WHERE pr.precio_unidad = SOME (
SELECT pr.precio_unidad FROM main.producto AS pr
WHERE pr.id_categoria=3)
ORDER BY precio_unidad
-- ############################################################
-- PRODUCTOS CUYO PRECIO UNITARIO ES DISTINTOS DE ALGUNO DE TODOS LOS PRECIOS DE PRODUCTOS CATEGORIA 3
SELECT  DISTINCT pr.id_producto,pr.nombre_producto,pr.precio_unidad,pr.id_categoria
FROM main.producto AS pr
WHERE pr.precio_unidad <> SOME (
SELECT pr.precio_unidad FROM main.producto AS pr
WHERE pr.id_categoria=3)
ORDER BY precio_unidad
-- ############################################################
-- PRODUCTOS CUYO PRECIO UNITARIO ES DISTINTOS DE TODOS LOS PRECIOS DE PRODUCTOS CATEGORIA 3
SELECT  DISTINCT pr.id_producto,pr.nombre_producto,pr.precio_unidad,pr.id_categoria
FROM main.producto AS pr
WHERE pr.precio_unidad <> ALL (
SELECT pr.precio_unidad FROM main.producto AS pr
WHERE pr.id_categoria=3)
ORDER BY precio_unidad
-- #####################################################
--CLIENTES QUE SOLO PIDIERON QUESO CABRALES EN TODOS SUS PEDIDOS
SELECT DISTINCT c.id_cliente,c.nombre_empresa FROM main.cliente AS c
JOIN main.pedido AS p ON(c.id_cliente=p.id_cliente)
JOIN main.detalle_pedido AS dp ON (dp.id_pedido=p.id_pedido)
JOIN main.producto AS pr ON(pr.id_producto=dp.id_producto)
WHERE pr.nombre_producto='Queso Cabrales' AND
NOT EXISTS(
SELECT 1
    FROM main.pedido AS p2
    JOIN main.detalle_pedido AS dp2
         ON dp2.id_pedido = p2.id_pedido
    JOIN main.producto AS pr2
         ON pr2.id_producto = dp2.id_producto
    WHERE p2.id_cliente = c.id_cliente
      AND pr2.nombre_producto <> 'Queso Cabrales'
);
-- #####################################################
SELECT c.id_cliente,
       c.nombre_empresa
FROM main.cliente AS c
WHERE NOT EXISTS (

    SELECT 1
    FROM main.pedido AS p
    WHERE p.id_cliente = c.id_cliente
      AND p.fecha_pedido BETWEEN '1996-04-30' AND '1996-05-31'
);
-- #####################################################
