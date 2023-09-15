# GraphMaker 
Un (muy) simple programa para dibujar grafos (i.e vértices y aristas). Escrito en C usando la biblioteca TIny GRaphics.

Hola chicxs! Como andan? GraphMaker es un proyectito que dibuja grafos con la idea de que si cualquiera quiere aportar codigo lo pueda hacer facilmente.

Para aportar codigo, realizar cambios, crear funciones, etc. debes seguir los siguientes pasos (parece mucho, pero creeme que es una pavada):

1. Click en Code -> Codespaces -> sign in
2. Entra con tu cuenta o crea una si no tenes.
3. Ahora que tenes tu cuenta, volve a github.com/simon2375/GraphMaker
4. click en Code -> Codespaces -> Create codespace on master
5. ve a main.c y escribi (sin borrar nada) tu apodo delante de //aqui estuvo: 
6. Veras que el chirimbolo debajo de la lupa tiene un circulo azul, hace click
7. Click en "confirmacion" -> "siempre"
8. en la linea 11 (sin #) escribi "Yo codeo en github >:)" 
9. cerra la ventanita de nombre COMMIT_EDITMSG
10. click en los tres puntitos a la derecha de "control de codigo fuente"
11. click en pull,push -> push to -> origin (si no te aparece origin, hace click en upstream -> crear bifurcacion)
12. click en el gatito github -> chirimbolito al lado de "solicitudes de incorporacion de cambios" -> al lado de MERGE -> "cambiar repositorio" -> "TuUsuario/GraphMaker" -> "master"
13. donde dice "Master" arriba de description escribi el titulo "Mi primer contribucion"
14. En description escribi "Agregue mi nombre delante de //aqui estuvo:"
15. click en "Create"
16. Felicidades! Realizaste tu primera contribucion :) una vez que sea aceptada, la veras reflejada en github.com/simon2375/GraphMaker

Para volver a contribuir, repeti los pasos 6-15

Para correr tu codigo desde tu codespace, debes seguir los siguientes pasos:

1. En la terminal ingresa:
   sudo apt-get update
2. En la terminal ingresa:
   sudo apt-get install mingw-w64
3. A partir de ahora para compilar ingresa:
   cd Project\ Files && x86_64-w64-mingw32-gcc -o ../MiGraphMaker.exe tigr.c Mouse.c Vertex.c Dijkstra.c OperationManager.c main.c -lopengl32 -lgdi32 && cd ..
4. Click derecho en MiGraphMaker -> Descargar... -> doble click en el MiGraphMaker.exe que descargaste
5. Si te aparece "Windows protegio tu PC" dale a Mas informacion -> ejecutar de todas formas
6. Listo! Ya sabes realizar como realizar modificaciones, compilar y ejecutar tu codigo :)
