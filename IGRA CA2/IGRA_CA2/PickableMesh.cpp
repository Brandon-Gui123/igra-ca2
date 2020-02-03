#include "PickableMesh.h"

#include <vector>       // for std::vector class

std::vector<PickableMesh*> PickableMesh::pickableMeshes{};

PickableMesh::PickableMesh(GameObject &gameObject) : Mesh{}, gameObject{gameObject}
{
}

PickableMesh::~PickableMesh()
{}

}
