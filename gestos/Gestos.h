
class Gesto{
  private:
  //Variables para almacenar los valores de cada dedo
    int pulgar_;
    int indice_;
    int medio_;
  //Almacena un umbral
    int umbral_;
    int codigo_[3];
    
  public:
    void datosSensores(int cp, int ci, int cm);
    //Establece los parametros
    void setParams(int pulgar, int indice, int medio, int umbral, int codigo[]);
    //Imprime los parametros establecidos
    void getParams();
    //Clasifica la informacion de entrada haciendo una comparacion con los valores almacenados
    void clasifica(int pulgar, int indice, int medio, int vector[]);
    
};

