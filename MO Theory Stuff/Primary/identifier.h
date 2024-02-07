#include "Vector.h"
#include <string>
#pragma once

enum Element
{
	H = 1, He,
	Li, Be, B, C,  N,  O,  F,  Ne,
	Na, Mg, Al, Si, P,  S,  Cl, Ar,
	K,  Ca, Sc, Ti, V,  Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr,
	Rb, Sr, Y,  Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe,
	Cs, Ba, 
	La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu,
	Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn,
	Fr, Ra, 
	Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr,
	Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Nh, Fl, Mc, Lv, Ts, Og
};


enum Group
{
	C_infinityv,
	D_infinityh,
	O_h,
	T_d,
	D_2h,
	D_3h,
	D_4h,
	D_2d,
	D_3d,
	D_4d,
	D_2,
	D_3,
	D_4,
	C_2,
	C_3,
	C_4,
	S_2,
	S_4,
	C_2h,
	C_3h,
	C_4h,
	C_2v,
	C_3v,
	C_4v,
	C_s,
	C_1,
	C_i,
};
enum Structure
{
	Linear,
	Trigonal_planar,
	Tetrahedral,
	Trigonal_bipyramidal,
	Octahedral,
};

const char* GroupName(Group pointGroup);
Group trigonal_planar_identifier(Vector<3> vec =Vector<3>{ {} });
Group linear_identifier(Vector<2> vec = Vector<2>{ {} });
Group tetrahedral_identifier(Vector<4> vec = Vector<4>{ {} });
Group trigonal_bipyramidal_identifier(Vector<5> vec = Vector<5>{ {} });
Group octahedral_identifier(Vector<6> vec = Vector<6>{ {} });
