// ============================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------------
//
// release       :
// release_date  :
//
// file          : include/CGAL/Triangulation_cell_3.h
// revision      : $Revision$
// author(s)     : Monique Teillaud <Monique.Teillaud@sophia.inria.fr>
//
// coordinator   : INRIA Sophia Antipolis (<Mariette.Yvinec@sophia.inria.fr>)
//
// ============================================================================

#ifndef CGAL_TRIANGULATION_CELL_3_H
#define CGAL_TRIANGULATION_CELL_3_H

#include <CGAL/basic.h>
#include <CGAL/Triangulation_short_names_3.h>

CGAL_BEGIN_NAMESPACE

template < class Tr >
class Triangulation_cell_3
  : public Tr::Triangulation_data_structure::Cell
{
  typedef typename Tr::Triangulation_data_structure::Vertex Vtds;
  typedef typename Tr::Triangulation_data_structure::Cell Ctds;

  typedef typename Tr::Vertex           Vertex;
  typedef typename Tr::Cell_handle      Cell_handle;
  typedef typename Tr::Vertex_handle    Vertex_handle;

public:

  typedef typename Tr::Geom_traits::Point_3 Point;

  Triangulation_cell_3()
    : Ctds() {}

  // Vertex access functions
  Vertex_handle vertex(int i) const
  {
    return  ((Vertex *)(Ctds::vertex(i)));
  }
    
  bool has_vertex(const Vertex_handle & v) const
  {
    return (Ctds::has_vertex( & (*v)) );
  }
    
  bool has_vertex(const Vertex_handle & v, int & i) const
  {
    return Ctds::has_vertex( &(*v), i);
  }

  int index(const Vertex_handle & v) const
  {
    return Ctds::index( &(*v));
  }

  //ACCESS FUNCTIONS
  Cell_handle neighbor(int i) const
  {
    return (Triangulation_cell_3 *)(Ctds::neighbor(i));
  }

  int index(Cell_handle c) const
  {
    return Ctds::index( &(*c));
  }

  Vertex_handle mirror_vertex(int i) const
    {
      return (Vertex *) Ctds::mirror_vertex(i);
    }

  bool has_neighbor(Cell_handle c) const
  {
    return Ctds::has_neighbor( &(*c));
  }

  bool has_neighbor(Cell_handle c, int & i) const
  {
    return Ctds::has_neighbor( &(*c), i);
  }
 
  Cell_handle handle()
  {
    return Cell_handle(this);
  }

 //Setting
  void set_vertices(Vertex_handle v0,
		    Vertex_handle v1,
		    Vertex_handle v2,
		    Vertex_handle v3)
  {
    Ctds::set_vertices(&(*v0), &(*v1), &(*v2), &(*v3));
  }
    
  void set_neighbors(Cell_handle n0,
		     Cell_handle n1,
		     Cell_handle n2,
		     Cell_handle n3)
  {
    Ctds::set_neighbors(&(*n0), &(*n1), &(*n2), &(*n3));
  }
    
  void set_vertex(int i, Vertex_handle v)
  {
    Ctds::set_vertex(i, &(*v));
  }
    
  void set_neighbor(int i, Cell_handle n)
  {
    Ctds::set_neighbor(i, &(*n));
  }
};

CGAL_END_NAMESPACE

#endif // CGAL_TRIANGULATION_CELL_3_H
