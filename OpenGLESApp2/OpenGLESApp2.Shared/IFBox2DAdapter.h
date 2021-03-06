#pragma once

#include <GLES/gl.h>


#include <Box2D/Box2D.h>
#include <list>

#include <IFEngine.h>
//
//class Iifclass1 {
//public:
// ~Iifclass1() {
//  Free();
// }
// virtual void Init() {
//  Free();
// }
//private:
// virtual void Free(){
// }
// };



class ifCB2Body {
public:
 ifCB2Body(b2World *_World = NULL) {
  World = _World;
  body_def = NULL;
  body = NULL;
 }
 ~ifCB2Body() {
  Free();
 }
 void Init() {
  Free();
 }
 b2World *World;
 ////////////////////////////////////
 b2BodyDef *body_def;
 b2Body *body;
 S_listWrap_ptr<b2Shape, true> shape;
 S_listWrap_ptr<b2FixtureDef, true> fixture;
 ////////////////////////////////////
 //After body_def, body, shape and fixture have been prepared this function will create a body and add it to the world 
 void CreateBody() {
  if (World && !body) {
   body = World->CreateBody(body_def);
   typename std::list<b2Shape*>::iterator iters = shape.begin();
   for (typename std::list<b2FixtureDef*>::iterator iter = fixture.begin();
    iter != fixture.end();
    iter++) {
    (*iter)->shape = (*iters);
    body->CreateFixture(*iter);
    iters++;
   }
   shape.clear();
  }
 }
 //Called before CreateBody at least once
 void AddShapeAndFixture(b2Shape *_shape, b2FixtureDef *_fixture) {
  shape.push_back(_shape);
  fixture.push_back(_fixture);
 }
 //Input parameters:
//shape_index IN
// - index of shape
//vertices_count IN/OUT//  
// - IN  - maximum number of vertices vertices array can hold
// - OUT - number of vertices used
//vertices and vertices_mode OUT
// - vertices must have 2*vertices_count elements available, storing x1,y1,x2,y2,...
 bool BodyToVertices(unsigned int shape_index, unsigned int &vertices_count, float *vertices, GLenum &vertices_mode) {
  //[b2_maxPolygonVertices]
  for (typename std::list<b2FixtureDef*>::iterator iter = fixture.begin();
   iter != fixture.end();
   iter++) {
   switch ((*iter)->shape->m_type) {
   case b2Shape::e_chain:
   case b2Shape::e_edge:
    vertices_mode = GL_LINES;
    break;
   case b2Shape::e_polygon:
    vertices_mode = GL_LINE_LOOP;
    vertices_count = ((b2PolygonShape*)(*iter)->shape)->m_count;
    for (int cnt = 0; cnt < vertices_count; cnt++) {
     vertices[2 * cnt] = ((b2PolygonShape*)(*iter)->shape)->m_vertices[cnt].x;
     vertices[2 * cnt + 1] = ((b2PolygonShape*)(*iter)->shape)->m_vertices[cnt].y;
    }
    break;
   case b2Shape::e_circle:
    vertices_mode = GL_LINE_LOOP;
    break;
   }
  }
 }
 void Free() {
  if (World) {
   World->DestroyBody(body);
  }
  body = NULL;
  IF_NULL_DELETE(body_def);
  shape.clear();
  fixture.clear();
 }
};

class ifCB2BodyManager : public ifCB2Body {
public:
 ifCB2BodyManager() {
  World = NULL;
  OrderPending = false;
 }
 ~ifCB2BodyManager() {
  Free();
 }
 void Init() {
  Free();
 }
 void OrderBody() {
  if (!OrderPending) {
   Bodies.push_back(new ifCB2Body);
   Bodies.back()->World = World;
   Bodies.back()->body_def = new b2BodyDef;
   OrderPending = true;
  }
 }
 void MakeBody() {
  if (OrderPending) {
   OrderPending = false;
   Bodies.back()->CreateBody();
  }
 }
 void CancelOrder() {
  if (OrderPending) {
   OrderPending = false;
   Bodies.removeElement(Bodies.back());
  }
 }
 ifCB2Body* OrderedBody() {
  return  (OrderPending ? Bodies.back() : NULL);
 }
 //void Add
 b2World *World;
 S_listWrap_ptr<ifCB2Body, true> Bodies;
private:
 bool OrderPending;
 void Free() {
 }
public:

};



class ifCB2GameManager : public ifCB2BodyManager {
public:
 ifCB2GameManager() {
  velocityIterations = 8;   //how strongly to correct velocity
  positionIterations = 3;   //how strongly to correct position

  ResetClock();
 }
 void ResetClock() {
  clock_gettime(CLOCK_MONOTONIC, &temp_timespec);
  game_time_0 = temp_timespec;
 }
 void UpdateSim() {
  clock_gettime(CLOCK_MONOTONIC, &temp_timespec);
  //temp_int64 = timespec2ms64(&temp_timespec) - timespec2ms64(&game_time_0);
  temp_int64 = timespec2us64(&temp_timespec) - timespec2us64( &game_time_0 );
  game_time_0 = temp_timespec;
  timeStep = 1000.0f / (float)temp_int64;
  //timeThen = timeNow;
  World->Step( timeStep, velocityIterations, positionIterations );
 }
 void UpdateGraphics() {
  //list all bodies and draw them 
  unsigned int vertices_count;
  for( typename std::list<ifCB2Body*>::iterator iter = Bodies.begin(); iter != Bodies.end(); iter++ ){
   //get body position and rotation
   //b2Vec2 position = ->GetPosition();
   //float32 angle = body->GetAngle();
   //printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
   //Calculate rotation and transformation matrices

  }
  //call game update and draw functions
 }
 //Calculates conversion factor when presenting Box2D to graphic unit
 // pixels_per_box2d_unit is desired number of pixels on screen for delta Box coordinate 1. If we want 1 pixels for 0.1 box coord delta( one coordinate unit) we pass 10
 //We use smaller dimension of screen resolution as one unit of screen length 
 void CalculateBox2DSizeFactor(float pixels_per_box2d_unit = 10) {
  unsigned int ScreenPixels;
  if (screenResolutionX < screenResolutionY) {
   ScreenPixels = screenResolutionX;
  }
  else {
   ScreenPixels = screenResolutionY;
  }
  //Part of screen used by 1 box2d unit
  box2D_factor = 2.0 * ( pixels_per_box2d_unit / (float)ScreenPixels );
 }
 //This function transforms box2d coordinate to opengl es normalized coordinate where -1 is 0 on screen coordinates and 1 is the smaller of the resolutions
 float Coord_Box2D2OpenGLCoord(float _input_coord) {
  return _input_coord * box2D_factor - 1.0f;
 }
 //This function will transform box2d coordinates to absolute size in normalized opengl es coordinates
 float Size_Box2D2OpenGL(float _input_coord) {
  return _input_coord * box2D_factor;
 }
 float32 timeStep;
 int32 velocityIterations;   //how strongly to correct velocity
 int32 positionIterations;   //how strongly to correct position
 //Variables that determine scaling of box2d objects to our screen
 unsigned int screenResolutionX, screenResolutionY;//OpenGLES cooridinates are in range from -1 to 1 for width and heigth, where -1 is 0 in screen coordinates and 1 is las r/c pixel
 //All box2D coordinates are multiplied by this factor. Typical value is arround 0.0001
 float box2D_factor; 
protected:
 b2Vec2 *Gravity;
 b2World *World;
 struct timespec temp_timespec, game_time_0;
 int64_t temp_int64;
};


class ifCB2WorldManager :  public ifCB2GameManager {
public:
 ifCB2WorldManager() {
  Gravity = NULL;
  World = NULL;
 }
 ~ifCB2WorldManager() {
  Free();
 }
 void Init() {
  Free();
 }
 void MakeWorld(float32 gx, float32 gy) {
  Init();
  Gravity = new b2Vec2(gx,gy);
  World = new b2World(*Gravity);
 }
 void Free() {
  IF_NULL_DELETE(Gravity)
  IF_NULL_DELETE(World)
 }
public:
};



class ifCB2Adapter : public ifCB2WorldManager {
public:
 ifCB2Adapter() {

 }
 void MakeWorld(float32 gx, float32 gy) {
  ifCB2WorldManager::MakeWorld(gx, gy);
  ifCB2BodyManager::World = ifCB2WorldManager::World;
 }

};



// Define the gravity vector.
//b2Vec2 gravity;//(2.0f, -2.0f);

// Construct a world object, which will hold and simulate the rigid bodies.
//b2World world;//(gravity);

