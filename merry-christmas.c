#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

struct Vert {
	
	float x;
	float y;
	float z;

};

bool turn_on = false;

void fooKeyboard (unsigned char key, int xmouse, int ymouse) {
	
	switch (key){
		
		case 'f':
			if (!turn_on) {
				glEnable(GL_LIGHT0);
				turn_on = !turn_on;
			}
			else {
				glDisable(GL_LIGHT0);
				turn_on = !turn_on;
			}

		break;

		case 27:
			exit(0);
			break;
			
		default:
        break;
	}
}

void assign_color(GLfloat* input, GLfloat* color) {
	for (int i = 0; i<4; i++)
		input[i] = color[i];
}

int conf = 0;

GLfloat color_light1[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat color_light2[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat color_light3[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat color_light4[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat color_light5[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat color_light6[4] = {0.0, 0.0, 0.0, 1.0};
GLfloat color_light7[4] = {0.0, 0.0, 0.0, 1.0};

GLfloat white[4] 	= {	1.00, 1.000, 1.00, 1};
GLfloat red[4] 		= {	1.00, 0.000, 0.00, 1};
GLfloat green[4] 	= { 0.20, 0.700, 0.20, 1};
GLfloat blue[4] 	= { 0.00, 0.000, 0.60, 1};
GLfloat purple[4] 	= {	1.00, 0.000, 1.00, 1};
GLfloat yellow[4] 	= {	1.00, 1.000, 0.00, 1};
GLfloat brown[4] 	= {	0.36, 0.260, 0.13, 1};
GLfloat orange[4] 	= {	1.00, 0.647, 0.32, 1};

void timerFunc(int value) {
	conf = (conf+1)%3;
	
	switch (conf) {
		case 0:
			
			assign_color(color_light1, red);
			assign_color(color_light2, red);
			assign_color(color_light3, blue);
			assign_color(color_light4, blue);
			assign_color(color_light5, purple);
			assign_color(color_light6, purple);
			assign_color(color_light7, green);
			
			break;
			
		case 1:
			
			assign_color(color_light1, blue);
			assign_color(color_light2, purple);
			assign_color(color_light3, green);
			assign_color(color_light4, red);
			assign_color(color_light5, red);
			assign_color(color_light6, blue);
			assign_color(color_light7, purple);
			
			break;
			
		case 2:

			assign_color(color_light1, purple);
			assign_color(color_light2, blue);
			assign_color(color_light3, red);
			assign_color(color_light4, purple);
			assign_color(color_light5, blue);
			assign_color(color_light6, green);
			assign_color(color_light7, red);
			
			break;
	}
	
	glutTimerFunc( 450, timerFunc, 0 );
	glutPostRedisplay();
		
}
void light_init() {

	GLfloat no[4] 	= {0.0, 0.0, 0.0, 1.0};
	
	//Lights
	//Light0
	glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightf (GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.25);
	glLightf (GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.01);
	glLightf (GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
	
	//Light1
	glLightfv(GL_LIGHT1, GL_AMBIENT, no);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color_light1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	glLightf (GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.041);

	//Light2
	glLightfv(GL_LIGHT2, GL_AMBIENT, no);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, color_light2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white);
	glLightf (GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.041);
	
	//Light3
	glLightfv(GL_LIGHT3, GL_AMBIENT, no);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, color_light3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, white);
	glLightf (GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.041);
	
	//Light4
	glLightfv(GL_LIGHT4, GL_AMBIENT, no);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, color_light4);
	glLightfv(GL_LIGHT4, GL_SPECULAR, white);
	glLightf (GL_LIGHT4, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.041);
	
	//Light5
	glLightfv(GL_LIGHT5, GL_AMBIENT, no);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, color_light5);
	glLightfv(GL_LIGHT5, GL_SPECULAR, white);
	glLightf (GL_LIGHT5, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.041);
	
	//Light6
	glLightfv(GL_LIGHT6, GL_AMBIENT, no);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, color_light6);
	glLightfv(GL_LIGHT6, GL_SPECULAR, white);
	glLightf (GL_LIGHT6, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.041);
	
	//Light7
	glLightfv(GL_LIGHT7, GL_AMBIENT, no);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, color_light7);
	glLightfv(GL_LIGHT7, GL_SPECULAR, white);
	glLightf (GL_LIGHT7, GL_CONSTANT_ATTENUATION, 0.013);
	glLightf (GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.005);
	glLightf (GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.041);

}

void wall() {
	double x, y, z;
	double mx,my,mz;
	Vert V[4];
	double offset = 0.3;

	glPushMatrix();		

			for ( z = -40; z<40; z+=offset) { //scorre su z				
				
				for ( x=1; x<81; x+=offset) { //scorre su x
					glBegin(GL_QUADS);	

											
						V[0].x = x;
						V[0].y = 0;
						V[0].z = z;
												
						V[1].x = x+offset;
						V[1].y = 0;
						V[1].z = z;
						
						V[2].x = x+offset;
						V[2].y = 0;
						V[2].z = z+offset;													
						
						V[3].x = x;
						V[3].y = 0;
						V[3].z = z+offset;
						
											
						for (int i=0; i<4; i++) {
				
							mx = ( V[i].y - V[(i+1)%4].y) * ( V[i].z + V[(i+1)%4].z);									
							my = ( V[i].z - V[(i+1)%4].z) * ( V[i].x + V[(i+1)%4].x);										
							mz = ( V[i].x - V[(i+1)%4].x) * ( V[i].y - V[(i+1)%4].y);
								
						}
						
						glNormal3f(mx, my, mz);

						glVertex3f(V[0].x,V[0].y,V[0].z);	
						glVertex3f(V[1].x,V[1].y,V[1].z);	
						glVertex3f(V[2].x,V[2].y,V[2].z);	
						glVertex3f(V[3].x,V[3].y,V[3].z);	
					glEnd();												

						
				}
	
			}	
	
					
	glPopMatrix();
	
}


void Init() {	
	glClearColor (0,0,0,0);	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glEnable(GL_DEPTH_TEST);	

	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);

}

GLvoid drawScene() {
   	
	GLfloat no[4] 	= {0.0, 0.0, 0.0, 1.0};

	GLfloat centerX;
	GLfloat centerY;
   	GLfloat centerZ;  
	   
	centerX = 0;
	centerY = 0;
   	centerZ = 0;   
	
	Init();
	
	//Positions
	GLfloat position_1[4] = { 0.0, 69.5, 0.5, 1.0};
	GLfloat position_2[4] = {0, 0, 0, 1.0};

	//View
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();	
		glLoadIdentity();
	
		gluPerspective(60, 16/9, 1.0, 300.0);
		gluLookAt (0, 0, 50, 15, 0, 10, 0, 1, 0);	
	
		glMatrixMode( GL_MODELVIEW);	
	glPopMatrix();
	glLoadIdentity(); 
	//
	

	//quadratic
	GLUquadricObj *qobj0;
	qobj0 = gluNewQuadric(); 
	
	gluQuadricDrawStyle(qobj0, GLU_FILL);
	gluQuadricOrientation(qobj0, GLU_INSIDE);
	gluQuadricNormals(qobj0, GLU_SMOOTH);

	GLUquadricObj *qobj1;
	qobj1 = gluNewQuadric(); 
	
	gluQuadricDrawStyle(qobj1, GLU_FILL);
	gluQuadricOrientation(qobj1, GLU_INSIDE);
	gluQuadricNormals(qobj1, GLU_SMOOTH);
	
	GLUquadricObj *qobj2;
	qobj2 = gluNewQuadric(); 
	
	gluQuadricDrawStyle(qobj2, GLU_FILL);
	gluQuadricOrientation(qobj2, GLU_INSIDE);
	gluQuadricNormals(qobj2, GLU_SMOOTH);
	
	GLUquadricObj *qobj3;
	qobj3 = gluNewQuadric(); 
	
	gluQuadricDrawStyle(qobj3, GLU_FILL);
	gluQuadricOrientation(qobj3, GLU_INSIDE);
	gluQuadricNormals(qobj3, GLU_SMOOTH);
	//

	//drawing
	
	light_init();
	glLightfv (GL_LIGHT0, GL_POSITION, position_1);

	glTranslatef(0, -10,0);
   	glPushMatrix ();
   	
   			glTranslatef(20,0,-8);
			//tree
			glPushMatrix();
				glRotatef(-90, 1, 0,0);
				
				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , green);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
					
				gluCylinder (qobj1, 20, 5, 15, 200, 200);		
			glPopMatrix ();

			glPushMatrix();

				glTranslatef(0, 10, 0);
				glRotatef(-90, 1, 0,0);
				
				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , green);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				gluCylinder (qobj2, 15, 5, 15, 200, 200);		
				
			glPopMatrix();
			
			glPushMatrix();
				glTranslatef(0, 20, 0);
				glRotatef(-90, 1, 0,0);
				
				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , green);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				gluCylinder (qobj3, 10, 1, 15, 200, 200);		

				glutSolidCone(10, 20, 100, 100);
			glPopMatrix ();

			glPushMatrix();
				glTranslatef(0, -10, 0);
				glRotatef(-90, 1, 0,0);
				
				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , brown);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				gluCylinder (qobj0, 5, 5, 15, 100, 100);		
			glPopMatrix ();
			
			//addobbi
			//corone
			glPushMatrix();
		

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , white);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				glRotatef(40, 0, 1, 0);
				glPushMatrix();
					glTranslatef(0, 5, 2.5);
					glRotatef(100, 1, 0,0);
					glutSolidTorus(0.5, 15.8,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(0.5, 15, 1.1);
					glRotatef(100, 1, 0,0);
					glutSolidTorus(0.5, 12.5,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(0, 25, 1);
					glRotatef(100, 1, 0,0);
					glutSolidTorus(0.5, 8,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(0, 35, 0);
					glRotatef(100, 1, 0,0);
					glutSolidTorus(0.5, 3,50,50);
				glPopMatrix();
			glPopMatrix ();
			
			//sfere
			//sfere blu
			glPushMatrix();
		

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , blue);
				glMaterialfv(GL_FRONT, GL_SPECULAR , white);
				glMateriali	(GL_FRONT, GL_SHININESS, 120);
				
				glPushMatrix();
					glTranslatef(-15, 2, 12);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-6, 12, 13);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(0, 22, 10);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(3, 30, 5);
					glutSolidSphere(1,50,50);
				glPopMatrix();
			glPopMatrix ();
			
			//sfere rosse
			glPushMatrix();
		

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , red);
				glMaterialfv(GL_FRONT, GL_SPECULAR , white);
				glMateriali	(GL_FRONT, GL_SHININESS, 120);
				
				glPushMatrix();
					glTranslatef(7, 9, 10);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-14, 12, 5);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-8, 22, 6);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-3, 30, 5);
					glutSolidSphere(1,50,50);
				glPopMatrix();
			glPopMatrix ();

			//sfere viola
			glPushMatrix();
		

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , purple);
				glMaterialfv(GL_FRONT, GL_SPECULAR , white);
				glMateriali	(GL_FRONT, GL_SHININESS, 120);
				
				glPushMatrix();
					glTranslatef(0, 2, 19);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-14, 12, 5);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-6, 30, 0);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(2, 16, 12);
					glutSolidSphere(1,50,50);
				glPopMatrix();
			glPopMatrix ();


			//sfere gialle
			glPushMatrix();
		

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , yellow);
				glMaterialfv(GL_FRONT, GL_SPECULAR , white);
				glMateriali	(GL_FRONT, GL_SHININESS, 120);
				
				glPushMatrix();
					glTranslatef(-8, 2, 17);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(-19, 2, 3);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(10, 2, 16.5);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glTranslatef(2, 16, 12);
					glutSolidSphere(1,50,50);
				glPopMatrix();
				
			glPopMatrix ();
	glPopMatrix();
	
	//luci
	glPushMatrix();
						
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light1);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light1);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
				
					glTranslatef(10.5, 15.2, 0);
					glutSolidSphere(0.2,50,50);
					glLightfv (GL_LIGHT1, GL_POSITION, position_2);
				glPopMatrix();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light2);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light2);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
					glTranslatef(21, 13.3, 5.4);
					glLightfv (GL_LIGHT2, GL_POSITION, position_2);
					glutSolidSphere(0.2,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light3);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light3);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
					glTranslatef(6.1, 6, -1.4);
					glLightfv (GL_LIGHT3, GL_POSITION, position_2);
					glutSolidSphere(0.2,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light4);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light4);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
					glTranslatef(16, 24.5, -0.2);
					glLightfv (GL_LIGHT4, GL_POSITION, position_2);
					glutSolidSphere(0.2,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light5);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light5);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
					glTranslatef(14, 4, 8.25);
					glLightfv (GL_LIGHT5, GL_POSITION, position_2);
					glutSolidSphere(0.2,50,50);
				glPopMatrix();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light6);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light6);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
					glTranslatef(20, 34.5, -4.51);
					glLightfv (GL_LIGHT6, GL_POSITION, position_2);
					glutSolidSphere(0.2,50,50);
				glPopMatrix();

				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_EMISSION , color_light7);
					glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
					glMaterialfv(GL_FRONT, GL_DIFFUSE  , color_light7);
					glMaterialfv(GL_FRONT, GL_SPECULAR , white);
					glMateriali	(GL_FRONT, GL_SHININESS, 120);
					glTranslatef(25, 2.7, 9.65);
					glLightfv (GL_LIGHT7, GL_POSITION, position_2);
					glutSolidSphere(0.2,50,50);
				glPopMatrix();

	glPopMatrix();
			//
	glPushMatrix();
			//room
			//floor
			glPushMatrix();
				glTranslatef(-30, -9.5, 10);

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , white);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				wall();
			glPopMatrix ();
			
			//wallback
			glPushMatrix();
				glTranslatef(-30, 30, -30);
				glRotatef(90, 1, 0,0);

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , white);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				wall();
			glPopMatrix ();
			
			//wallr
			glPushMatrix();
				glTranslatef(40, -11, 10);
				glRotatef(90, 0, 0,1);
			
				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , white);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				wall();
			glPopMatrix ();

			//ceiling
			glPushMatrix();
				glTranslatef(-30,70, 10);
				glRotatef(180, 1, 0,0);

				glMaterialfv(GL_FRONT, GL_EMISSION , no);
				glMaterialfv(GL_FRONT, GL_AMBIENT  , no);
				glMaterialfv(GL_FRONT, GL_DIFFUSE  , white);
				glMaterialfv(GL_FRONT, GL_SPECULAR , no);
				glMateriali	(GL_FRONT, GL_SHININESS, 0);
				
				wall();
			glPopMatrix ();

	glPopMatrix ();

	
	/***************************/

	glutSwapBuffers();
}
	
int main (int argc, char* argv[]) {

	glutInitDisplayMode (GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1300,1000);
	glutCreateWindow(argv[0]);
	glutKeyboardFunc(fooKeyboard);	
	glutSetCursor(GLUT_CURSOR_NONE);
	glutTimerFunc( 32, timerFunc, 0 );
	glutDisplayFunc(drawScene);
	glutMainLoop();
	
	return 0;
}
