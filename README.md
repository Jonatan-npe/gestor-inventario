# **Proyecto final ALSE**
## Gestor de inventario
Grupo: 
- Jonatan García Vásquez
- Ivan Daniel Carpentier Rodriguez
- Leydi Juliana Solorza Gonzales

Ejecutable:
- Ejecutable -> [Inventario](/build/Desktop-Debug/Inventario)

Clases principales:
- Logica de la ventana emergente ([Component](/Component)):
    - header -> [component.h](/Component/ComponentDialog.h)
    - Implementación -> [component.cpp](/Component/ComponentDialog.cpp)
- Base de datos ([Database](/Database)):
    - header -> [DatabaseManager.h](/Database/DatabaseManager.h)
    - Implementacón -> [DatabaseManager.cpp](/Database/DatabaseManager.cpp)
- Modelos y librerias necesarias ([Models](/Models)):
    - ComponentModel:
        - Header -> [ComponentModel.h](/Models/ComponentModel.h)
        - Implementación -> [ComponentModel.cpp](/Models/ComponentModel.cpp)
    - CustomFilterProxyModel:
        - Header -> [CustomFilterProxyModel.h](/Models/CustomFilterProxyModel.h)
        - Implementación -> [CustomFilterProxyModel.cpp](/Models/CustomFilterProxyModel.cpp)
- Nodo principal:
    - Header -> [Inventario.h](/inventario.h)
    - Implementación -> [Inventario.cpp](/inventario.cpp)
- Programa principal -> [main.cpp](/main.cpp)

Interfaces graficas:
- Ventanas emergentes -> [ComponentDialog.ui](/Component/ComponentDialog.ui)
- Ventana principal -> [inventario.ui](/inventario.ui)

Documentación:
- Manuel de usuario -> [Manuel de usuario.pdf](/Documentacion/Manuel%20de%20usuario.pdf)
- Documentación del programa -> [Documentación ALSE.pdf](/Documentacion/Documentación%20ALSE.pdf)