#pragma once
#include <vector>

/**
 * @brief Divide una cadena en partes usando un carácter como patrón.
 * Complejidad: O(n)
 * 
 * @param str Cadena que se dividirá.
 * @param pattern Carácter utilizado como patrón para dividir la cadena.
 * @return Vector de cadenas resultantes después de la división.
 */
vector<string> split(string str, char pattern) {
    int posInit = 0; 
    int posFound = 0; 
    string splitted;
    vector<string> results; 
    
    // Mientras se encuentren coincidencias del patrón
    while (posFound >= 0) {
        posFound = str.find(pattern, posInit); // Busca la siguiente coincidencia del patrón
        splitted = str.substr(posInit, posFound - posInit); // Obtiene la parte dividida
        posInit = posFound + 1; // Actualiza la posición de inicio para la próxima búsqueda
        results.push_back(splitted); // Agrega la parte dividida al vector de resultados
    }
    
    return results; // Devuelve el vector de resultados
}


/**
 * @brief Obtiene el número de mes a partir de un nombre de mes abreviado.
 * Complejidad: O(1) 
 * 
 * @param key Nombre abreviado del mes.
 * @return Número de mes correspondiente como una cadena.
 */
string getMonth(string key) {
    // Mapeo de nombres de meses abreviados a números de mes
    map<string, string> MONTHS {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };

    return MONTHS[key] + ""; // Retorna el número de mes correspondiente como una cadena
}


/**
 * @brief Agrega ceros a la izquierda de una cadena hasta alcanzar un tamaño específico.
 * Complejidad: O(n)
 * @param text Cadena a la que se agregarán ceros a la izquierda.
 * @param size Tamaño deseado de la cadena resultante.
 * @return Cadena con ceros agregados a la izquierda para alcanzar el tamaño especificado.
 */

string addZero(string text, int size) {
    string result = "";
    // Agrega ceros a la cadena hasta alcanzar el tamaño deseado
    for (int i = text.size(); i < size; i++) {
        result += "0";
    }
    return result + text; // Devuelve la cadena resultante
}


