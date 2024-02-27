# Programa Emisor y Receptor para Módulo NRF24L01 PA - LNA 📡

Este proyecto consiste en implementar un programa de emisor y receptor utilizando dos placas Arduino y los módulos NRF24L01 PA - LNA para establecer una comunicación inalámbrica bidireccional de datos.

## Descripción 🛠️

El programa incluye dos partes:

- **Emisor:** Este código se carga en una placa Arduino que tiene conectado un módulo NRF24L01 PA - LNA. El emisor envía datos al receptor a través de la radio NRF24L01.

- **Receptor:** Este código se carga en otra placa Arduino que también tiene un módulo NRF24L01 PA - LNA conectado. El receptor recibe los datos enviados por el emisor y realiza las acciones correspondientes según los datos recibidos.

## Componentes Necesarios 📦

- Dos placas Arduino (p. ej., Arduino Uno o Arduino Nano)
- Dos módulos NRF24L01 PA - LNA
- Adaptadores de voltaje para los módulos (si es necesario)
- Conexión a una fuente de alimentación (pilas, batería, etc.)

## Instrucciones de Uso 📝

1. **Cableado:** Conecta los módulos NRF24L01 PA - LNA a las placas Arduino siguiendo el esquemático proporcionado en el código.

2. **Configuración:** Asegúrate de configurar correctamente las direcciones de los módulos NRF24L01 en el código del emisor y el receptor.

3. **Carga de Código:** Carga el código del emisor en una placa Arduino y el código del receptor en otra placa Arduino utilizando el IDE de Arduino o tu entorno de desarrollo preferido.

4. **Prueba:** Una vez cargados los códigos, alimenta las placas Arduino y observa la comunicación inalámbrica entre el emisor y el receptor.

## Notas 📝

- Asegúrate de utilizar los adaptadores de voltaje adecuados si los módulos NRF24L01 PA - LNA funcionan con voltajes diferentes a los de las placas Arduino.
- Es posible que necesites agregar capacitores cerca de los módulos NRF24L01 PA - LNA para una mejor estabilidad en la comunicación.

## Contribuciones 🚀

¡Contribuciones son bienvenidas! Si tienes ideas para mejorar el proyecto, corregir errores o agregar nuevas características, no dudes en abrir un "issue" o enviar un "pull request".

## Créditos 🙌

Este proyecto fue creado por PICAIO SAS y está inspirado en proyectos similares de la comunidad de Arduino y electrónica.

## Licencia 📝

Este proyecto está bajo la licencia [MIT](LICENSE).
