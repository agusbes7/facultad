--EJERCICIOS 9,12,13,16 OTRA VEZ
-- EJERCICIO 9
SELECT DISTINCT loc_prov.nombre AS proveedor ,loc_clie.nombre AS cliente FROM main.proveedor AS prov
JOIN main.localidad AS loc_prov ON (loc_prov.id_localidad=prov.id_localidad)
JOIN main.producto AS pr ON (pr.id_proveedor=prov.id_proveedor)
JOIN main.detalle_pedido AS dp ON (dp.id_producto=pr.id_producto)
JOIN main.pedido AS pe ON (dp.id_pedido=pe.id_pedido)
JOIN main.cliente AS c ON (c.id_cliente=pe.id_cliente)
JOIN main.localidad AS loc_clie ON (loc_clie.id_localidad=c.id_localidad)
Where loc_prov.id_localidad <> loc_clie.id_localidad
-- ################################################
-- EJERCICIO 13
SELECT DISTINCT l.nombre FROM main.localidad AS l
JOIN main.proveedor AS p ON(l.id_localidad=p.id_localidad)
-- Solo hay localidades donde hay proveedores y ahora me aseguro que no haya clientes en esa localidad
WHERE NOT EXISTS(
SELECT * FROM main.cliente AS c
WHERE l.id_localidad =c.id_localidad)
ORDER BY nombre ASC
-- ################################################
-- EJERCICIO 16
SELECT l.nombre FROM main.localidad AS l
JOIN main.proveedor AS p ON(l.id_localidad=p.id_localidad)
JOIN main.cliente AS c ON(l.id_localidad=c.id_localidad)
JOIN main.empleado AS e ON(l.id_localidad=e.id_localidad)
-- ################################################
-- EMPLEADOS que tienen a su cargo al menos a otro empleado
SELECT e.nombre,e.apellido FROM main.empleado AS e
WHERE EXISTS
(SELECT * FROM main.empleado AS e2
WHERE e2.jefe=e.id_empleado);
-- ############################################
-- CLIENTES QUE EN EL dia asignado hicieron pedidos, pero no de producto de categoria 1
SELECT c.nombre_empresa,p.fecha_pedido FROM main.pedido AS p
JOIN main.cliente AS c ON(c.id_cliente=p.id_cliente)
WHERE p.fecha_pedido='1996-05-01' 
 AND NOT EXISTS 
 (SELECT * FROM main.detalle_pedido AS dp
JOIN main.producto AS pr ON (pr.id_producto=dp.id_producto)
WHERE dp.id_pedido=p.id_pedido AND pr.id_proveedor=1)
-- ###############################################
SELECT p.nombre_proveedor, COUNT(*) AS productos_Suspendidos FROM main.proveedor AS p
JOIN main.producto AS pr ON(pr.id_proveedor=p.id_proveedor)
GROUP BY nombre_proveedor, pr.suspendido
-- #################################################
-- Contar la cantidad de productos distintos que comercializa la empresa
SELECT p.id_proveedor, COUNT(*) AS cantidad_productos FROM main.producto AS p
GROUP BY id_proveedor
ORDER BY cantidad_productos DESC
-- #################################################
-- COntar la cantidad total de productos que han sido pedido por cada categoria
SELECT pr.id_categoria,COUNT (dp.cantidad) AS cantidad FROM main.pedido  AS p
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
JOIN main.producto AS pr ON(pr.id_producto=dp.id_producto)
GROUP BY id_categoria
ORDER BY  cantidad DESC
-- ###########################################################
-- CUENTO las unidades totales pedidas x c/cliente en los pedidos del periodo definido
SELECT c.id_cliente,c.nombre_empresa,c.fecha_alta,
SUM(dp.cantidad)AS cantidadTotal,
MAX(dp.precio_unidad),
MIN(dp.precio_unidad)
FROM main.cliente AS c
JOIN main.pedido AS p ON(p.id_cliente=c.id_cliente)
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
WHERE p.fecha_pedido BETWEEN '1996-04-01' AND '1996-06-30'
GROUP BY p.id_pedido, nombre_empresa,fecha_alta
ORDER BY id_cliente DESC
--  ##################################################################################
-- OBTENGO la cantidad de veces que se pidio un producto en un pedido y luego la cantidad de unidades y las suma
SELECT pr.id_producto,pr.nombre_producto,pr.id_categoria,COUNT(pr.id_producto) as cantidad,SUM(dp.cantidad) AS unidades
FROM main.pedido AS p
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
JOIN main.producto AS pr ON(dp.id_producto=pr.id_producto)
GROUP BY pr.id_producto,nombre_producto,id_categoria
ORDER BY cantidad ASC
LIMIT 1
-- ################################################
SELECT c.nombre_empresa,c.nombre_contacto,SUM(dp.precio_unidad*dp.cantidad) AS total ,sum(dp.cantidad) AS unidades FROM main.pedido AS p
JOIN main.cliente AS c ON(c.id_cliente=p.id_cliente)
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
GROUP BY nombre_empresa,nombre_contacto
HAVING  SUM(dp.precio_unidad*dp.cantidad)>20000 OR sum(dp.cantidad)>300
-- ################################################################
SELECT p.id_cliente,c.nombre_empresa,c.nombre_contacto,c.direccion,c.telefono, SUM(dp.cantidad) AS unidades_compra
FROM main.pedido AS p
JOIN main.cliente AS c ON(p.id_cliente=c.id_cliente)
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
GROUP BY p.id_cliente,c.nombre_empresa,c.nombre_contacto,c.direccion,c.telefono
ORDER BY unidades_Compra DESC
LIMIT 1
--  #################################################
-- PARA OBTENER EL MENOR O MAYOR NO LOS USO COMO FUNCIONES DE AGREGACION 
SELECT p.id_cliente,c.nombre_empresa,c.nombre_contacto,c.direccion,c.telefono
FROM main.pedido AS p
JOIN main.cliente AS c ON(p.id_cliente=c.id_cliente)
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
GROUP BY p.id_cliente,c.nombre_empresa,c.nombre_contacto,c.direccion,c.telefono
HAVING COUNT (dp.cantidad)>=ALL(
SELECT COUNT(*)
FROM main.pedido AS p1
JOIN main.cliente AS c1 ON(p1.id_cliente=c1.id_cliente)
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p1.id_pedido)
GROUP BY p1.id_cliente)
-- >#######################################################
-- empleado con la menor cantidad de pedidos
SELECT e.* FROM main.empleado AS e
JOIN main.pedido AS p ON(p.id_empleado=e.id_empleado)
GROUP BY e.id_empleado
HAVING COUNT(id_pedido)<=ALL
(SELECT COUNT (*)
 FROM main.empleado AS e2
JOIN main.pedido AS p2 ON(p2.id_empleado=e2.id_empleado)
GROUP BY e2.id_empleado)
-- #########################################################
-- EJERCICIO 34
SELECT c.id_cliente,c.nombre_empresa,e.nombre,e.apellido, SUM(dp.cantidad*dp.precio_unidad) FROM main.pedido AS p
JOIN main.cliente AS c ON(c.id_cliente=p.id_cliente)
JOIN main.empleado AS e ON(e.id_empleado=p.id_empleado)
JOIN main.detalle_pedido AS dp ON(dp.id_pedido=p.id_pedido)
GROUP BY p.id_pedido,c.id_cliente,c.nombre_empresa,e.nombre,e.apellido 
HAVING SUM(dp.cantidad*dp.precio_unidad) >= ALL
(SELECT  SUM(dp2.cantidad*dp2.precio_unidad) FROM main.pedido AS p2
JOIN main.cliente AS c2 ON(c2.id_cliente=p2.id_cliente)
JOIN main.empleado AS e2 ON(e2.id_empleado=p2.id_empleado)
JOIN main.detalle_pedido AS dp2 ON(dp2.id_pedido=p2.id_pedido)
GROUP BY p2.id_pedido)
-- #####################################################
-- EJERCICIO 35
SELECT DISTINCT c.id_cliente,c.nombre_empresa,c.id_localidad,SUM(dp1.cantidad) FROM main.cliente as c
JOIN main.pedido AS p1 ON (p1.id_cliente=c.id_cliente)
JOIN main.detalle_pedido AS dp1 ON (p1.id_pedido=dp1.id_pedido)
WHERE c.id_localidad=81
GROUP BY c.id_cliente
HAVING SUM(dp1.cantidad) > SOME(
SELECT  SUM(dp2.cantidad) FROM main.cliente as c2
JOIN main.pedido AS p2 ON (p2.id_cliente=c2.id_cliente)
JOIN main.detalle_pedido AS dp2 ON (p2.id_pedido=dp2.id_pedido)
WHERE c2.id_localidad=126
GROUP BY c2.id_cliente)
-- #####################################################
--EJERCICIO 36
SELECT p.id_pedido,    p.id_cliente,
       COUNT(DISTINCT dp.id_producto) AS productos_distintos
FROM main.pedido AS p
JOIN main.detalle_pedido AS dp  ON dp.id_pedido = p.id_pedido
GROUP BY p.id_pedido,
         p.id_cliente
HAVING COUNT(DISTINCT dp.id_producto) >= 20;
-- #####################################################
SELECT c.id_cliente,   c.nombre_empresa
FROM main.cliente AS c
WHERE NOT EXISTS (
    SELECT 1    FROM main.pedido AS p
    JOIN main.detalle_pedido AS dp  ON dp.id_pedido = p.id_pedido
    WHERE p.id_cliente = c.id_cliente
    GROUP BY p.id_pedido
    HAVING COUNT(DISTINCT dp.id_producto) <= 5);

 