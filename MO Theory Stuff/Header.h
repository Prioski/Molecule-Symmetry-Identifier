#pragma once
#ifndef HEADER_H
#define HEADER_H

enum Structure;
enum Group;
Group trigonal_planar_identifier(Vector<3> vec);
Group linear_identifier(Vector<2> vec);
Group tetrahedral_identifier(Vector<4> vec);
Group trigonal_bipyramidal_identifier(Vector<5> vec);
Group octahedral_identifier(Vector<6> vec);

#endif
