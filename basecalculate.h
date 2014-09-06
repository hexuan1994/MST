#ifndef BASECALCULATE_H
#define BASECALCULATE_H

#include "Delaunay.h"
#include <fstream>
#include <map>
#include <QDebug>


class BaseCalculate
{
public:
    BaseCalculate();
    void openfile(const string inputName);
    void addvertex(vertex);
    void removevertex(vertex);
    void DelCalculate();
    vertexSet GetVertexs() { return m_vertices; }
    edgeSet GetEdges() { return m_edges; }

private:
    bool changeflag = 0;
    map<vertex,vertex> root;
    Delaunay DCalculate;
    vertexSet m_vertices;
    triangleSet m_triangles;
    edgeSet m_edges;
    void Kruskal();
    vertex Find(vertex x);
    void Union(vertex a, vertex b);

};

#endif // BASECALCULATE_H
