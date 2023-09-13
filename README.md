# GraphMaker
A (very) simple program for drawing graphs (i.e vertices and edges). Written in C using the TIny GRaphics library.

Hola chicxs! Como andan? GraphMaker es un proyectito que dibuja grafos con la idea de que si cualquiera quiere aportar codigo lo pueda hacer facilmente.
Para aportar codigo a graph maker, debes:

1. Descargar github desktop, abrir y crear una cuenta

2. Hacer click en "Clone an existing Repository from the Internet..." y luego en "URL"

4. Copiar y pegar simon2375/GraphMaker en la primera barra.

5. Hacer click en choose... y elegir una carpeta vacia donde guardar el proyecto.

6. Abrir tu editor de texto favorito y aporta tu codigo.

7. en GithubDesktop, hace click en "Commit to master" (podes poner un titulo como "agregue la funcion ContarCiclos()"

8. click en push origin -> fork this repository -> continue -> push origin -> create pull request -> create pull request

9. Listo! Solo queda esperar a que los cambios sean aceptados.

Para crear el ejecutable en tu PC, usa el comando: 

Windows (en MINGW64):

gcc -o GraphMaker.exe tigr.c Mouse.c Vertex.c Dijkstra.c OperationManager.c main.c -lopengl32 -lgdi32 && GraphMaker.exe

Linux:

gcc -o GraphMaker.exe tigr.c Mouse.c Vertex.c Dijkstra.c OperationManager.c main.c -lGLU -lGL -lX11 && ./GraphMaker.exe

Mac:

gcc -o GraphMaker.exe tigr.c Mouse.c Vertex.c Dijkstra.c OperationManager.c main.c -framework OpenGL -framework Cocoa


PD:
Actualmente, no se por que, el programa no ejecuta correctamente en linux ni wsl, solo en windows con MINGW, es algo a corregir mas adelante.
