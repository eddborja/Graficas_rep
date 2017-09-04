#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>	
#include <vector>

//Identificador del manager de VBOs para 1 geomatria.
GLuint vao;

void Initializa()
{
	//Vamos a crear una lista que va a lamancenar las posiciones
	// en 2 dimensiones de un triangulo 
	// Esto es un CPU y RAM

	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	std::vector<glm::vec3> colors;

	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	glGenVertexArrays(1, &vao);
	//Le decimos  a OpenGl que queremos utilizar el manager.
	// Todos los VBOs que creemos a aprtir de este punto y hasta 
	//que desactivemos esto VAO, se van a asosicar a este manager.
	glBindVertexArray(vao);

	//Identificador del VBO de posiciones. Aqui lo vamos a almacenar.
	GLuint positionsVBO;
	//Creamos un VBO y almacenamos el id en la variable positions VBO
	glGenBuffers(1, &positionsVBO);
	// LE DECIMOS  A OPEN GL QUE LO QUEREMOS UTILIZAR OCMO UN ATRIBUTO.
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//ASIGNAMOS LOS DATOS AL BUFFER Y LOS MANDAMOS A LA TARJETA DE VIDEO. 
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(),
		positions.data(), GL_STATIC_DRAW);
	// Quiero activar el atributo con indice 0 en la tarjeta de video
	glEnableVertexAttribArray (0);
	//Configuramos el atributo con indice 0 en la tarjeata de video. 
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	//Desactivamos el uso del VBO de posiciones
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(),
		colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Ya no quiero utilizar el VA0,Ya no se asosciaran mas VBOs a este VAO
	glBindVertexArray(0);

	



}

void MainLoop() {
	//bORRAMOS EL BUFFER DE COLOR Y PROFUNDIDAD SIEMPRE AL INICIO DE UN NUEVO FRAME
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Paso 1 no lo podemos hace aun 

	//Paso 2 : Activar un VAO 
	glBindVertexArray(vao);
	//Paso 3 : Dibujamos
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//Paso 4: Desactivemos el VAO
	glBindVertexArray(0);

	//Paso 5: aun no lo podemos hacer

	

	//INTERCAMBIAR LOS BUFFERS (EL QUE SE ESTABA RENDEREANDO CON EL QUE SE ESTABA MOSTRANDO 
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	//Inicializamos freeglut
	//Freeglut se encarga de generar ventanas y manejar ventanas
	//Utilizamos freeglut para crear una ventana donde vamos a dibujar 
	glutInit(&argc, argv);
	//Tenemos que informar que queremos trabajar con el pipeline clasico, o sea Opengl viejito)
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	//Freeglut nos permite configurar eventos que ocurren en la ventana, un evento que nos interesa es cuando
	//alguien cierra la ventana, en este caso simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//ESTAMOS CONfigurando el framebuffer. En este caso estamos solicitando un buffer de color true color RGBA
	//un buffer de profundidad y un segundo buffer para renderear (evitamos parpadeos al renderear)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Solicitamos una ventana de 400 x 400 pixeles 
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hellow World OpenGL");
	//Asociar una funcion de render, esta funcion se mandara a llamar para dibujar un frame
	glutDisplayFunc(MainLoop);
	//Inicializamos GLEW, esta libreria se encarga de obtener el API de OpenGl de nuestra tarjeta de video.
	glewInit();
	//Configurar OpenGL. Este es el olor por default del buffer de color en el framebuffer
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	
	//Configurar la memoria que la aplicacion va a necesitar
	Initializa();

	
	//Iniciamos la aplicacion grafica, el main se pausará en esta linea hasta que se cierre la ventana de OpenGL
	glutMainLoop();
	return 0;
}