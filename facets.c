// This file requires at least C99 to compile

/**
 * @file   facets.c
 * @author Jean-Cédric Chappelier <jean-cedric.chappelier@epfl.ch>
 * @author Merlin Nimier-David <merlin.nimier-david@epfl.ch>
 *
 * @copyright EPFL 2021
**/
/**
 * @section DESCRIPTION
 *
 * Template du homework du cours CS-207, année 2021.
**/

#include <limits.h>  // For INT_MAX
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // For EXIT_SUCCESS/FAILURE

// ----------------------------------------------
//   ___             _            _
//  / __|___ _ _  __| |_ __ _ _ _| |_ ___
// | (__/ _ \ ' \(_-<  _/ _` | ' \  _(_-<
//  \___\___/_||_/__/\__\__,_|_||_\__/__/

#define NB_VERTICES_MAX 128
#define NB_FACES_MAX    128
#define NB_FACETS_PER_VERTEX_MAX 20
#define NO_FACET ((Facet*) NULL)

// ----------------------------------------------
//  _____
// |_   _|  _ _ __  ___ ___
//   | || || | '_ \/ -_|_-<
//   |_| \_, | .__/\___/__/
//       |__/|_|


/* TODO: Définissez ici les types demandés :
 *     - Vector
 *     - Vertex
 *     - Facet
 */


// ======================================================================
/**
 * Attempts to register `p` as the `vertex_i`th vertex of face `f`,
 * and to add a reference to `f` in `p`.
 *
 * Returns 1 if successful, 0 otherwise.
 */
int register_vertex_for_face(Vertex* p, Facet* f, size_t vertex_i)
{
    // TODO
    return 0;
}


// ======================================================================
/**
 * Lets the user input their desired number of 3D vertices (< nb_max)
 * by first giving the number of vertices and then giving the 3D coordinates
 * of each vertex.
 *
 * The vertices are stored in `tab`.
 * Returns the number of vertices succesfully received.
 */
size_t query_vertices(Vertex tab[], size_t nb_max)
{
    // TODO
    return 0;
}

// ======================================================================
/**
 * Lets the user input their desired number of triangular
 * facets (< nb_max) by first giving the number of facets,
 * and then giving the index (0-based) of its 3 vertices.
 *
 * The facets are stored in `faces`, and `pts` is updated
 * with pointers to the facets referring to it.
 * Returns the number of facets successfully received.
 */
size_t query_facets(Facet faces[], size_t nb_max,
                    Vertex pts[], size_t nb_vertices)
{
    // TODO
    return 0;
}

// ======================================================================
#define PREC 1e-10
#define round(x) (fabs(x) < PREC ? 0.0 : x)
void vector_println(const Vector* pv)
{
    printf("(%.4g, %.4g, %.4g)\n", round(pv->x), round(pv->y), round(pv->z));
}

// ======================================================================
/* TODO: Définissez ici les fonctions :
 *    - vertices_to_vector()
 *    - vector_product()
 *    - vector_norm()
 */

// ======================================================================
Vector facet_normal(size_t index, const Facet t[], size_t nb, double *out_area)
{
    Vector rez = { 0.0, 0.0, 0.0 };
    // TODO
    return rez;
}

// ======================================================================
Vector mesh_barycenter(const Vertex vertices[], size_t nb_vertices)
{
    Vector rez = { 0.0, 0.0, 0.0 };
    // TODO
    return rez;
}

// ======================================================================
void print_mesh_stats(const Vertex p[], size_t nb_vertices,
                      const Facet f[], size_t nb_facets)
{
    const Vector bary = mesh_barycenter(p, nb_vertices);
    putchar('\n');
    printf("La forme contient %zu sommets et %zu facettes.\n", nb_vertices, nb_facets);
    printf("Le barycentre est : ");
    vector_println(&bary);
    putchar('\n');
}

// ======================================================================
void print_vertex_info(size_t index, const Vertex p[], size_t nb)
{
    // TODO
    // printf("Le sommet %03zu appartient à %zu facettes : ", index, .....);
    // TODO
    putchar('\n');
}

// ======================================================================
void print_face_info(size_t index, const Facet f[], size_t nb)
{
    if (index >= nb) {
        fprintf(stderr, "Erreur : impossible de calculer la normale à la face %zu\n",
                index);
        fprintf(stderr, "Erreur : les indices des facettes sont entre 0 et %zu\n", nb - 1);
        return;
    }

    double area = 0.0;
    const Vector n = facet_normal(index, f, nb, &area);
    printf("Face %03zu : aire = %.4g, normale = ", index, area);
    vector_println(&n);
}

// ----------------------------------------------
//  __  __      _
// |  \/  |__ _(_)_ _
// | |\/| / _` | | ' \
// |_|  |_\__,_|_|_||_|

#define MAX_PRINT 10
int main(void)
{
    Vertex vertices[NB_VERTICES_MAX];
    const size_t nb_vertices = query_vertices(vertices, NB_VERTICES_MAX);

    Facet facets[NB_FACES_MAX];
    const size_t nb_facets = query_facets(facets, NB_FACES_MAX,
                                          vertices, nb_vertices);

    print_mesh_stats(vertices, nb_vertices, facets, nb_facets);

    for (size_t i = 0; i < (nb_vertices < MAX_PRINT ? nb_vertices : MAX_PRINT); ++i) {
        print_vertex_info(i, vertices, nb_vertices);
    }

    for (size_t i = 0; i < nb_facets; ++i) {
        print_face_info(i, facets, nb_facets);
    }

    return EXIT_SUCCESS;
}
