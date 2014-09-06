#include "basecalculate.h"
#include <algorithm>
#include <math.h>

REAL edgelength(edge edge_0)
{
    PointF tempPoint;
    tempPoint = edge_0.m_pV0->GetPoint() - edge_0.m_pV1->GetPoint();
    return (sqrt((tempPoint.X)*(tempPoint.X) + (tempPoint.Y)*(tempPoint.Y)));
}

bool Kruskalcmp(const edge &edge_1,const edge &edge_2)
{
    qDebug() << " here ";
    return edgelength(edge_1) > edgelength(edge_2);
}



BaseCalculate::BaseCalculate()
{
}

void BaseCalculate::openfile(const string inputName)
{
    ifstream fin;
    int PointNum;
    fin.open(inputName.c_str());
    fin >> PointNum;
    for(int i = 0;i < PointNum;i++)
    {
        int tempX,tempY;
        fin >> tempX >> tempY;
        m_vertices.insert(vertex(tempX,tempY));
    }
    changeflag = 1;
}

void BaseCalculate::addvertex(vertex pV)
{
    m_vertices.insert(pV);
    changeflag = 1;
}

void BaseCalculate::removevertex(vertex pV)
{
    m_vertices.erase(pV);
}

void BaseCalculate::DelCalculate()
{   qDebug() <<" 4";
    m_triangles.clear();
    m_edges.clear();

    DCalculate.Triangulate(m_vertices,m_triangles);
    DCalculate.TrianglesToEdges(m_triangles,m_edges);
    Kruskal();
    changeflag = 0;
}

void BaseCalculate::Kruskal()
{
    vIterator vI = m_vertices.begin();
    while(vI != m_vertices.end())
    {
        root[*vI] = *vI;
        vI++;
    }
    edge *K_edges = new edge[m_edges.size()];
    int tempnumber = m_edges.size();
    int Ki = -1;
    while(!m_edges.empty())
    {
        Ki++;
        K_edges[Ki] = *m_edges.begin();
        m_edges.erase(m_edges.begin());
    }

    m_edges.clear();
    std::sort(K_edges,K_edges + tempnumber,Kruskalcmp);  ////////////....add ();
    for(;Ki >= 0;Ki--)
    {
        if(!(Find(*(K_edges[Ki].m_pV0))==Find(*(K_edges[Ki].m_pV1))))
        {
            m_edges.insert(K_edges[Ki]);
            Union(*(K_edges[Ki].m_pV0),*(K_edges[Ki].m_pV1));
        }
    }
}

vertex BaseCalculate::Find(vertex x)
{
    vertex i,temp;
    i = x;
    while(!(i==root[i]))
        i=root[i];
    while(!(i==root[x]))
    {
        temp=root[x];
        root[x]=i;
        x = temp;
    }

    return i;
}

void BaseCalculate::Union(vertex a,vertex b)
{
    a=Find(a);
    b=Find(b);
    if(!(a==b))
    root[a]=b;
}
