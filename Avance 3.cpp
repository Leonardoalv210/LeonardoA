/*
Leonardo Alvarado Menéndez A01705998

Por lo comentado por el profesor en la entrega del 03/12/19, cambie el tema a Autos, aunque el consepto sigue siendo parcido, guardar
y registrar tipos de autos en una marca y de estos en una bodega.
*/
#include <iostream>
#include <iomanip>
using namespace std;

//Clase Auto, la cual tendra herencia de los distintos tipos de autos 
class Auto
{
	private://Atributos privados
		int capacidad_peso;
		string tipo_combus, motor_id;
	public://Metodos publicos
		Auto(int, string, string);//Constructor de la clase
		void set_capacidad_peso(int capacidad_peso);//getter y setter
		int get_capacidad_peso();
		string get_tipo_combus();
		void set_motor_id(string motor);
		string get_motor_id();
};

Auto::Auto(int cap_pes, string combus, string _motor)//constructor
{
    capacidad_peso=cap_pes;
	tipo_combus=combus;
	motor_id=_motor;
		
}

//Se declaran los getters y setters
void Auto::set_capacidad_peso(int cap_pes)
{
	capacidad_peso=cap_pes;
};

int Auto::get_capacidad_peso()
{
	return capacidad_peso;
};

string Auto::get_tipo_combus()
{
	return tipo_combus;
};

void Auto::set_motor_id(string _motor)
{
	motor_id=_motor;
};

string Auto::get_motor_id()
{
	return motor_id;
};

class Familiar : public Auto//Hereda las funciones publicas de Auto, con las cuales puede alterar las privadas
{
	private:
		int asientos;
	public:
		Familiar(int=1000, string="Diesel", string="4 cilindros", int=7);//Constructor de la clase Familiar donde ya se declaran valores estandares
		int get_asientos();//getters y setters
		void set_asientos(int asientos);
};

//Constructor de la clase con la herencia, lo que va despues de los ":" son los datos heredados 
Familiar::Familiar(int cap_pes, string combus, string _motor, int _asientos) : Auto (cap_pes, combus, _motor)
{
	asientos=_asientos;
}

int Familiar::get_asientos()
{
	return asientos;
};

void Familiar::set_asientos(int _asientos)
{
	asientos=_asientos;
};

class Autobus : public Auto
{
	private:
		float max_peso;
	public:
		Autobus(int=1000, string="Premium", string="8 cilindros", float=3000);
		float get_max_peso();
		void set_max_peso(float max_pes);
};

Autobus::Autobus(int cap_pes, string combus, string _motor, float max_pes) : Auto (cap_pes, combus, _motor)
{
	max_peso=max_pes;
}

float Autobus::get_max_peso()
{
	return max_peso;
};

void Autobus::set_max_peso(float max_pes)
{
	max_peso=max_pes;
};

class Carreras : public Auto
{
	private:
		float max_vel;
	public:
		Carreras(int=1000, string="Premium", string="8 cilindros", float=320);
		float get_max_vel();
		void set_max_vel(int max_v);
};

Carreras::Carreras(int cap_pes, string combus, string _motor, float max_v) : Auto (cap_pes, combus, _motor)
{
	max_vel=max_v;
}

float Carreras::get_max_vel()
{
	return max_vel;
};

void Carreras::set_max_vel(int max_v)
{
	max_vel=max_v;
};

//Se declara la case Marca, la cual es una composicion de la clase Auto
class Marca
{
	private://atributos privadas
		string nombre;
	public://metodos publicos
		Marca(string="");//Constructor de la clase
		void set_nombre(string nombre);//getters y setters
		string get_nombre();
		void get_datos_familiar(Familiar, Familiar);//Metodo para ver los datos de la clase Familiar
		void get_datos_carreras(Carreras, Carreras);//Metodo para ver los datos de la clase Carreras
		void get_datos_autobus(Autobus, Autobus);//Metodo para ver los datos de la clase Autobus
};

Marca::Marca(string nom)
{
	nombre=nom;
}

void Marca::set_nombre(string nom)
{
	nombre=nom;
};

string Marca::get_nombre()
{
	return nombre;
};

void Marca::get_datos_familiar(Familiar a, Familiar b)
{
	cout << "El auto a:" << endl;
	cout << "Con un peso de: " << a.get_capacidad_peso() << "kg"<< endl;
	cout << "Usa combustible tipo: " << a.get_tipo_combus() << endl;
	cout << "Motor: " << a.get_motor_id() << endl;
	cout << "Numero de asientos: " << a.get_asientos() << endl;
	cout << endl;
	cout << "El auto b:" << endl;
	cout << "Con un peso de: " << b.get_capacidad_peso() << "kg"<< endl;
	cout << "Usa combustible tipo: " << b.get_tipo_combus() << endl;
	cout << "Motor: " << b.get_motor_id() << endl;
	cout << "Numero de asientos: " << b.get_asientos() << endl;
	cout << endl;
};

void Marca::get_datos_carreras(Carreras c, Carreras d)
{
	cout << "El auto c:" << endl;
	cout << "Con un peso de: " << c.get_capacidad_peso() << "kg"<< endl;
	cout << "Usa combustible tipo: " << c.get_tipo_combus() << endl;
	cout << "Motor: " << c.get_motor_id() << endl;
	cout << "Velocidad maxima: " << c.get_max_vel() << endl;
	cout << endl;
	cout << "El auto d:" << endl;
	cout << "Con un peso de: " << d.get_capacidad_peso() << "kg"<< endl;
	cout << "Usa combustible tipo: " << d.get_tipo_combus() << endl;
	cout << "Motor: " << d.get_motor_id() << endl;
	cout << "Velocidad maxima: " << d.get_max_vel() << endl;
	cout << endl;
};

void Marca::get_datos_autobus(Autobus e, Autobus f)
{
	cout << "El auto e:" << endl;
	cout << "Con un peso de: " << e.get_capacidad_peso() << "kg"<< endl;
	cout << "Usa combustible tipo: " << e.get_tipo_combus() << endl;
	cout << "Motor: " << e.get_motor_id() << endl;
	cout << "Peso maximo: " << e.get_max_peso() << endl;
	cout << endl;
	cout << "El auto f:" << endl;
	cout << "Con un peso de: " << f.get_capacidad_peso() << "kg"<< endl;
	cout << "Usa combustible tipo: " << f.get_tipo_combus() << endl;
	cout << "Motor: " << f.get_motor_id() << endl;
	cout << "Peso maximo: " << f.get_max_peso() << endl;
	cout << endl;
};

//Clase Bodega, de la cual la clase Marca es una composicion 
class Bodega
{
	private:
		int num_marca;//Indice del arreglo donde se guardan las marcas
		string nombre;//Nombre de la bodega
		Marca marca[100];//Arreglo donde se guardan las marcas
	public:
		Bodega(int=0, string="");//Constructor
		void get_marca();//Para ver los objetos del arreglo
		void set_marca(string nom);//Aqui se crean los objetos de la clase Marca y se guardan en un arreglo
		void set_nombre(string _nombre);//Set nombre
		string get_nombre();//Get nombre
};

//Constructor
Bodega::Bodega(int num_marc, string _nombre)
{
	num_marca=num_marc;
	nombre=_nombre;
}

string Bodega::get_nombre()//Get
{
	return nombre;
};

void Bodega::set_nombre(string _nombre)//Set
{
	nombre=_nombre;
};

void Bodega::set_marca(string nom)
{
	Marca f1(nom);//Se crea el nuevo objeto de la clase Marca
	marca[num_marca] = f1;//Se guarda en el arreglo
	num_marca++;//Aumenta el indice para poder guardar más
};

void Bodega::get_marca()
{
	for (int i=0;i<num_marca;i++)
	{
		cout << "Marca" << i+1 << " " << marca[i].get_nombre() << endl;
	}
};

int main(){
	//Se crean los objetos
	Familiar a, b(1000,"Magma","alternativo",253);
	Carreras c, d(500,"Premium","reaccion",290);
	Autobus e, f(3000,"Diesel","8 cilindros",5000);
	Bodega a1(0,"Bodega Pepe");//Se crea el objeto de Bodega
	Marca f2("Mazda");//Se crea un objeto Marca
	//se declaran las variables que se usaran despues en el programa
	int accion=0;
	int desicion=0;
	float max_pes, max_v;
	int cap_pes, _asientos, num_contenedores;
	string _motor, _nombre, nom;
	while (desicion!=3)
	{
		cout << "1-Ver datos Bodega" << endl;
		cout << "2-Ver o modificar datos de autos" << endl;
		cout << "3-Salir" << endl;
		cin >> desicion;
		if (desicion==1)
		{
			int des_bodega=0;
			while (des_bodega!=3)
			{
				cout << "1-Insertar nueva Marca" << endl;
				cout << "2-Ver datos de Bodega" << endl;
				cout << "3-Salir" << endl;
				cin >> des_bodega;
				if (des_bodega==1)
				{
					cout << "Nombre de la Marca: ";
					cin >> nom;
					a1.set_marca(nom);//Se crea el objeto de la marca dentro del objero Bodega
				}
				if (des_bodega==2)
				{
					cout << "La bodega " << "'" << a1.get_nombre() << "'" << " cuenta con las marcas: " << endl;
					a1.get_marca();
				}
				if (des_bodega==3)
				{
					cout << "Bye" << endl;
				}
				if (des_bodega < 1 || 3 < des_bodega)
				{
					cout << "Opcion no disponible" << endl;
				}
				
			}			
		}
		if (desicion==2)
		{
			while (accion!=3)
			{
				//Menú para insertar datos, ver o salir
				cout << "1-Insertar datos a autos" << endl;
				cout << "2-Ver datos" << endl;
				cout << "3-Salir" << endl;
				cin >> accion;
				if (accion==1)
				{
					int insertar=0;
					while(insertar!=4)
					{
						//Menú para elegir a que tipo de auto se le quieren insertar datos 
						cout << "1-Insertar datos de auto tipo familiar" << endl;
						cout << "2-Insertar datos de auto tipo carreras" << endl;
						cout << "3-Insertar datos de auto tipo autobus" << endl;
						cout << "4-Salir" << endl;
						cin >> insertar;
						if (insertar==1)
						{
//Todos los metodos para agregar datos de la clase Auto que heredo a familiar se usan y el metodo propio de la clase Familiar
							cout << "Familiar a" << endl;
							cout << "Insertar peso del auto: ";
							cin >> cap_pes;
							a.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							a.set_motor_id(_motor);
							cout <<"Numero de asientos: ";
							cin >> _asientos;
							a.set_asientos(_asientos);
							cout << endl;
							cout << "Familiar b" << endl;
							cout << "Insertar peso del auto: ";
							cin >> cap_pes;
							b.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							b.set_motor_id(_motor);
							cout <<"Numero de asientos: ";
							cin >> _asientos;
							b.set_asientos(_asientos);							
						}
						if (insertar==2)
						{
							//Se hace lo mismo que para los autos de Carreras
							cout << "Carreras c" << endl;
							cout << "Insertar peso del auto: ";
							cin >> cap_pes;
							c.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							c.set_motor_id(_motor);
							cout <<"Vel max: ";
							cin >> max_v;
							d.set_max_vel(max_v);
							cout << endl;
							cout << "Carreras d" << endl;
							cout << "Insertar peso del auto: ";
							cin >> cap_pes;
							d.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							d.set_motor_id(_motor);
							cout <<"Vel max: ";
							cin >> max_v;
							d.set_max_vel(max_v);															
						}
						if (insertar==3)
						{
							//Se hace lo mismo para los autos de autobus	
							cout << "Autobus e" << endl;
							cout << "Insertar peso del auto: ";
							cin >> cap_pes;
							e.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							e.set_motor_id(_motor);
							cout <<"Peso max: ";
							cin >> max_pes;
							e.set_max_peso(max_pes);
							cout << endl;
							cout << "Autobus f" << endl;
							cout << "Insertar peso del auto: ";
							cin >> cap_pes;
							f.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							f.set_motor_id(_motor);
							cout <<"Peso max: ";
							cin >> max_pes;
							f.set_max_peso(max_pes);															
						}
						if (insertar==4)
						{
							cout << "Bye" << endl;
						}
						if (insertar < 1 || 4 < insertar)
						{
							cout <<"Opcion no disponible" << endl;
						}
					}
				}
				if (accion==2)
				{
					int consultar=0;
					while (consultar!=4)
					{
						//Menú para elegir de cual auto le quieres ver sus datos
						cout << "1-Consultar datos de auto tipo familiar" << endl;
						cout << "2-Consultar datos de auto tipo Carreras" << endl;
						cout << "3-Consultar datos de auto tipo Autobus" << endl;
						cout << "4-Salir" << endl;
						cin >> consultar;
						//Se usan los getters para leer los datos de los autos
						if (consultar==1)
						{
							f2.get_datos_familiar(a, b);
						}
						if (consultar==2)
						{
							f2.get_datos_carreras(c, d);
						}
						if (consultar==3)
						{
							f2.get_datos_autobus(e, f);
						}
						if (consultar==4)
						{
							cout << "Bye" << endl;
						}
						if (consultar < 1 || 4 < consultar)
						{
							cout <<"Opcion no disponible" << endl;
						}
				    }
				}
				if (accion==3)
				{
					cout << "Bye" << endl;
				}
				if (accion < 1 || 3 < accion)
				{
					cout <<"Opcion no disponible" << endl;
				}
			}
		}
		if (desicion==3)
		{
			cout << "Bye" << endl;
		}
		if (desicion < 1 || 3 < desicion)
		{
			cout <<"Opcion no disponible" << endl;
		}
	}
}
