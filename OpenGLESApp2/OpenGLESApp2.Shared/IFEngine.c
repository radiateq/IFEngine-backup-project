#include "IFEngine.h"




ifTbodiesList BodiesList;



void PrepareDraw(){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DrawBodies() {

 glMatrixMode(GL_MODELVIEW);
 glEnableClientState(GL_VERTEX_ARRAY);
 glEnableClientState(GL_TEXTURE_COORD_ARRAY);
 




 for( int bodies_count = 0; bodies_count < BodiesList.bodies_cnt; bodies_count++ ){
  BodiesList.bodies[bodies_count]->vertices;
   BodiesList.bodies[bodies_count]->indices;
 }

 
 //if indicescnt>0 glDrawElements else glDrawArrays


glMatrixMode(GL_MODELVIEW);
 //GLfloat workMatrix1[16], workMatrix2[16];
 //glLoadIdentity(); 
 //glRotatef(_rotation_x, 1, 0, 0);  // X
 //glGetFloatv(GL_MODELVIEW, workMatrix1);
 //glLoadIdentity();
 //glRotatef(_rotation_y, 0, 1, 0);          // Y
 //glGetFloatv(GL_MODELVIEW, workMatrix2);


 static double testme = 0.8;
 static double testmespeed = 0.04;


 MatrixXf m1(4, 4), m2(4, 4), m3(4, 4);
 float mfa1[16], mfa2[16], mfa3[16];
 glLoadIdentity();
 testme += testmespeed * ((float)temp_int64 * 0.0001);
 glScalef(testme, testme, 1.0);
 if (((testme > 20.0) && (testmespeed > 0)) || ((testme < 0.4) && (testmespeed < 0))) testmespeed *= -1;
 static double LastAnimationInput = 0;
 if ((((TS_Cube_Test_Update_User_Data*)p_user_data)->Animation_Direction_Y) != LastAnimationInput) {

  LastAnimationInput = (((TS_Cube_Test_Update_User_Data*)p_user_data)->Animation_Direction_Y) / ((((TS_Cube_Test_Update_User_Data*)p_user_data)->screenHeight)*0.5);
  glTranslatef(0.0, (1.0 - LastAnimationInput), -0.5);
  LastAnimationInput = (((TS_Cube_Test_Update_User_Data*)p_user_data)->Animation_Direction_Y);
 }
 else {
  glTranslatef(0, testme / 20.0 - 0.8, -0.5);//-0.2 - testme / 60.0);
 }
 //glTranslatef( 0, 0, -0.2 );
 //glRotatef( _rotation_y, 0, 1, 0 );          // Y
 //glRotatef( _rotation_x, 1, 0, 0 );  // X
 glRotatef(_rotation_x, 0, 0, 1);  // Z
 //glTranslatef(0, testme / 20.0 - 0.8, 0.0);
 //glGetFloatv(GL_MODELVIEW_MATRIX, mfa1);
 //glLoadIdentity();
 //glGetFloatv(GL_MODELVIEW_MATRIX, mfa3);
 //glRotatef(_rotation_x, 0, 0, 1);  // z                                  
 //glGetFloatv(GL_MODELVIEW_MATRIX, mfa2);
 //
 //glLoadIdentity();
 //glScalef(testme, testme, 1.0);
 //glTranslatef(0, testme / 20.0 - 0.8, -0.2 - testme / 60.0);
 //glGetFloatv(GL_MODELVIEW_MATRIX, mfa3);
 //glRotatef(_rotation_x, 0, 0, 1);  // z                                  
 //glGetFloatv(GL_MODELVIEW_MATRIX, mfa3);
 //
 //CopyFloat16ToMatrix(m1, mfa1);
 //CopyFloat16ToMatrix(m2, mfa2);
 //m3 = m1 * m2;
 //
 //CopyMatrix16ToFloat(m3,mfa1);
 ////glRotatef(_rotation_x, 1, 1, 1);  // should be ignored
 //glLoadMatrixf(mfa1);





  //glMultMatrixf(workMatrix1);
  //glLoadIdentity();


  //glRotatef(_rotation_y, 0, 0, 1);          // Y


 // glEnableClientState(GL_COLOR_ARRAY);
 // glColorPointer(4,GL_FLOAT,0, colors);


 glFrontFace(GL_CCW);
 glVertexPointer(3, GL_FLOAT, sizeof(GLfloat) * 3, vertices);

 glEnable(GL_TEXTURE_2D);
 glBindTexture(GL_TEXTURE_2D, textInt);
 glTexCoordPointer(2, GL_FLOAT, sizeof(GLfloat) * 2, UVcoordinates);
 //GLenum error = glGetError();

 glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);




 //BodiesList.bodies_cnt

 //GLfloat workMatrix1[16], workMatrix2[16];
 //glLoadIdentity(); 
 //glRotatef(_rotation_x, 1, 0, 0);  // X
 //glGetFloatv(GL_MODELVIEW, workMatrix1);
 //glLoadIdentity();
 //glRotatef(_rotation_y, 0, 1, 0);          // Y
 //glGetFloatv(GL_MODELVIEW, workMatrix2);

}