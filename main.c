#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char** argv ) {

  screen s;
  struct matrix *edges;
  struct matrix *transform;
  struct matrix *polygons;
  color c;
  c.red = 156;
  c.green = 100;
  c.blue = 200;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  polygons = new_matrix( 4, 4 );
  
  add_polygons( polygons, 100, 100, 0, 200, 100, 0, 100, 200, 0 );
  draw_polygons( polygons, s, c );

  display( s );

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );
  
  free_matrix( transform );
  free_matrix( edges );
}  
