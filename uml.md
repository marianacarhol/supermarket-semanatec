##Diagrama de clases
```mermaid
classDiagram
    class Ingrediente {
        -std::string nom
        -std::string unidad
        -int id
        -int cant
        +Ingrediente(int id, const std::string& nom, const std::string& unidad, int cant)
        +std::string getNom() const
        +void setNom(const std::string& nom)
        +std::string getUnidad() const
        +void setUnidad(const std::string& unidad)
        +int getId() const
        +int getCant() const
        +void setCant(int cant)
    }

    class Inventario {
        +std::vector<Ingrediente> inventarioIngredientes
        +int getCantidad(const Ingrediente& ingrediente) const
        +void setCantidad(Ingrediente& ingrediente, int cantidad)
        +std::string getNom(const Ingrediente& ingrediente) const
        +std::vector<Ingrediente> leerDesdeArchivo(const std::string& nombreArchivo) const
        +void imprimir(const std::vector<Ingrediente>& inventarioIngredientes) const
        +void actualizar(std::vector<Ingrediente>& ingredientes, const std::vector<int>& ingredientesIDs, int op)
    }

    class Menu {
        -int opcion1
        -int opcion2
        -int opcion3
        +Menu()
        +Menu(int opcion1, int opcion2, int opcion3)
        +int printOpcion1()
        +int printOpcion2(int opcion2)
        +int printOpcion3()
    }

    class Platillo {
        -std::string nom
        -std::string tipo
        -std::vector<int> ingredientes
        -std::string receta
        +Platillo()
        +Platillo(const std::string& nom, const std::string& tipo, const std::vector<int>& ingredientes, const std::string& receta)
        +std::string getNom() const
        +std::string getTipo() const
        +std::vector<int> getIngredientes() const
        +std::string getReceta() const
        +void leerArchivo(const string& nombreArchivo, const Inventario& inventario, int tipoPlatillo, const std::vector<Ingrediente>& baseDatos)
        +void mostrarIngredientes() const
        +std::vector<int> leerArchivoIngredientes(const std::string& nombreArchivo, int tipoPlatillo)
        +void compararIngredientes(const std::vector<Ingrediente>& baseDatos, const std::vector<int>& ingredientes) const
    }

    Inventario --> Ingrediente : contiene
    Platillo --> Ingrediente : usa
