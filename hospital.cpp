#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Paciente {
    int expediente;
    string nombre;
    int edad;
    string sexo;
    string telefono;
    string motivo;
};

struct Doctor {
    int clave;
    string nombre;
    string especialidad;
    string turno;
};

struct Cita {
    int folio;
    int expediente;   
    int claveDoctor; 
    string fecha;
    string hora;
    string motivo;
    string estado;    
};

vector<Paciente> pacientes;
vector<Doctor> doctores;
vector<Cita> citas;

struct Medicamento {
    int clave;
    string nombre;
    int existencias;
};

vector<Medicamento> medicamentos;
const int MINIMO = 5;

void registrarPaciente() {
    Paciente p;
    cout << "Numero de expediente: ";
    cin >> p.expediente;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, p.nombre);
    cout << "Edad: ";
    cin >> p.edad;
    cin.ignore();
    cout << "Sexo: ";
    getline(cin, p.sexo);
    cout << "Telefono: ";
    getline(cin, p.telefono);
    cout << "Motivo de consulta: ";
    getline(cin, p.motivo);
    pacientes.push_back(p);
    cout << "Paciente registrado.\n";
}

void buscarPaciente() {
    int exp;
    cout << "Expediente a buscar: ";
    cin >> exp;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].expediente == exp) {
            cout << pacientes[i].nombre << ", " << pacientes[i].edad
                 << " anios, tel: " << pacientes[i].telefono << endl;
            return;
        }
    }
    cout << "No encontrado.\n";
}

void listarPacientes() {
    for (int i = 0; i < pacientes.size(); i++) {
        cout << pacientes[i].expediente << " | " << pacientes[i].nombre
             << " | " << pacientes[i].edad << " | " << pacientes[i].sexo
             << " | " << pacientes[i].telefono << " | " << pacientes[i].motivo << endl;
    }
}

void modulo1() {
    int op;
    do {
        cout << "\n--- MODULO 1: PACIENTES ---\n";
        cout << "1. Registrar paciente\n2. Buscar por expediente\n";
        cout << "3. Mostrar listado\n0. Volver\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: registrarPaciente(); break;
            case 2: buscarPaciente(); break;
            case 3: listarPacientes(); break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}


void registrarDoctor() {
    Doctor d;
    cout << "Clave: ";
    cin >> d.clave;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, d.nombre);
    cout << "Especialidad: ";
    getline(cin, d.especialidad);
    cout << "Turno: ";
    getline(cin, d.turno);
    doctores.push_back(d);
    cout << "Doctor registrado.\n";
}

void buscarDoctor() {
    int op;
    cout << "Buscar por: 1. Clave  2. Especialidad\nOpcion: ";
    cin >> op;
    cin.ignore();

    bool encontrado = false;
    if (op == 1) {
        int clave;
        cout << "Clave: ";
        cin >> clave;
        for (int i = 0; i < doctores.size(); i++) {
            if (doctores[i].clave == clave) {
                cout << doctores[i].nombre << " | " << doctores[i].especialidad
                     << " | " << doctores[i].turno << endl;
                encontrado = true;
            }
        }
    } else if (op == 2) {
        string esp;
        cout << "Especialidad: ";
        getline(cin, esp);
        for (int i = 0; i < doctores.size(); i++) {
            if (doctores[i].especialidad == esp) {
                cout << doctores[i].clave << " | " << doctores[i].nombre
                     << " | " << doctores[i].turno << endl;
                encontrado = true;
            }
        }
    }
    if (!encontrado) cout << "No se encontro.\n";
}

void contarPorEspecialidad() {
    for (int i = 0; i < doctores.size(); i++) {
        
        bool yaContada = false;
        for (int j = 0; j < i; j++) {
            if (doctores[j].especialidad == doctores[i].especialidad) {
                yaContada = true;
                break;
            }
        }
        if (yaContada) continue;

        int total = 0;
        for (int k = 0; k < doctores.size(); k++) {
            if (doctores[k].especialidad == doctores[i].especialidad) total++;
        }
        cout << doctores[i].especialidad << ": " << total << endl;
    }
}

void modulo2() {
    int op;
    do {
        cout << "\n--- MODULO 2: DOCTORES ---\n";
        cout << "1. Registrar doctor\n2. Buscar\n";
        cout << "3. Doctores por especialidad\n0. Volver\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: registrarDoctor(); break;
            case 2: buscarDoctor(); break;
            case 3: contarPorEspecialidad(); break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}


bool existePaciente(int exp) {
    for (int i = 0; i < pacientes.size(); i++)
        if (pacientes[i].expediente == exp) return true;
    return false;
}

bool existeDoctor(int clave) {
    for (int i = 0; i < doctores.size(); i++)
        if (doctores[i].clave == clave) return true;
    return false;
}

void agendarCita() {
    Cita c;
    c.folio = citas.size() + 1;

    cout << "Expediente del paciente: ";
    cin >> c.expediente;
    if (!existePaciente(c.expediente)) {
        cout << "Ese paciente no existe.\n";
        return;
    }
    cout << "Clave del doctor: ";
    cin >> c.claveDoctor;
    if (!existeDoctor(c.claveDoctor)) {
        cout << "Ese doctor no existe.\n";
        return;
    }
    cin.ignore();
    cout << "Fecha (dd/mm/aaaa): ";
    getline(cin, c.fecha);
    cout << "Hora (hh:mm): ";
    getline(cin, c.hora);
    cout << "Motivo de la cita: ";
    getline(cin, c.motivo);
    c.estado = "programada";

    citas.push_back(c);
    cout << "Cita agendada con folio " << c.folio << endl;
}

void cambiarEstado() {
    int folio, op;
    cout << "Folio de la cita: ";
    cin >> folio;
    for (int i = 0; i < citas.size(); i++) {
        if (citas[i].folio == folio) {
            cout << "Nuevo estado: 1. Atendida  2. Cancelada\nOpcion: ";
            cin >> op;
            if (op == 1) citas[i].estado = "atendida";
            else if (op == 2) citas[i].estado = "cancelada";
            else { cout << "Opcion invalida\n"; return; }
            cout << "Estado actualizado.\n";
            return;
        }
    }
    cout << "Folio no encontrado.\n";
}

void mostrarCita(const Cita& c) {
    cout << "Folio " << c.folio << " | Exp: " << c.expediente
         << " | Dr: " << c.claveDoctor << " | " << c.fecha << " "
         << c.hora << " | " << c.motivo << " | " << c.estado << endl;
}

void consultarCitas() {
    int op, id;
    bool hay = false;
    cout << "Consultar por: 1. Paciente  2. Doctor\nOpcion: ";
    cin >> op;
    cout << "Expediente o clave: ";
    cin >> id;

    for (int i = 0; i < citas.size(); i++) {
        if ((op == 1 && citas[i].expediente == id) ||
            (op == 2 && citas[i].claveDoctor == id)) {
            mostrarCita(citas[i]);
            hay = true;
        }
    }
    if (!hay) cout << "No hay citas.\n";
}

void modulo3() {
    int op;
    do {
        cout << "\n--- MODULO 3: CITAS ---\n";
        cout << "1. Agendar cita\n2. Cambiar estado\n";
        cout << "3. Consultar citas\n0. Volver\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: agendarCita(); break;
            case 2: cambiarEstado(); break;
            case 3: consultarCitas(); break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}

void registrarMedicamento() {
    Medicamento m;
    cout << "Clave: ";
    cin >> m.clave;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, m.nombre);
    cout << "Existencias: ";
    cin >> m.existencias;
    medicamentos.push_back(m);
    cout << "Medicamento registrado.\n";
}

void consultarInventario() {
    for (int i = 0; i < medicamentos.size(); i++) {
        cout << medicamentos[i].clave << " | " << medicamentos[i].nombre
             << " | " << medicamentos[i].existencias << endl;
    }
}

void alertaExistencias() {
    bool hayAlerta = false;
    cout << "\n--- MEDICAMENTOS CON POCAS EXISTENCIAS (Menor a " << MINIMO << ") ---\n";
    for (int i = 0; i < medicamentos.size(); i++) {
        if (medicamentos[i].existencias < MINIMO) {
            cout << medicamentos[i].clave << " | " << medicamentos[i].nombre
                 << " | Existencias: " << medicamentos[i].existencias << endl;
            hayAlerta = true;
        }
    }
    if (!hayAlerta) {
        cout << "No hay medicamentos por debajo del minimo.\n";
    }
}

void moverInventario() {
    int clave;
    cout << "Clave del medicamento: ";
    cin >> clave;

    int index = -1;
    for (int i = 0; i < medicamentos.size(); i++) {
        if (medicamentos[i].clave == clave) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Medicamento no encontrado.\n";
        return;
    }

    cout << "Medicamento: " << medicamentos[index].nombre 
         << " | Stock actual: " << medicamentos[index].existencias << endl;
    
    int tipo, cantidad;
    cout << "Tipo de movimiento:\n1. Entrada\n2. Salida\nOpcion: ";
    cin >> tipo;

    if (tipo == 1) {
        cout << "Cantidad a ingresar: ";
        cin >> cantidad;
        if (cantidad > 0) {
            medicamentos[index].existencias += cantidad;
            cout << "Entrada registrada con exito. Nuevo stock: " << medicamentos[index].existencias << endl;
        } else {
            cout << "Cantidad invalida.\n";
        }
    } else if (tipo == 2) {
        cout << "Cantidad a retirar: ";
        cin >> cantidad;
        if (cantidad > 0) {
            if (cantidad <= medicamentos[index].existencias) {
                medicamentos[index].existencias -= cantidad;
                cout << "Salida registrada con exito. Nuevo stock: " << medicamentos[index].existencias << endl;
            } else {
                cout << "Error: No hay suficientes existencias para realizar esta salida.\n";
            }
        } else {
            cout << "Cantidad invalida.\n";
        }
    } else {
        cout << "Opcion de movimiento invalida.\n";
    }
}

void modulo4() {
    int op;
    do {
        cout << "\n--- MODULO 4: MEDICAMENTOS ---\n";
        cout << "1. Registrar medicamento\n2. Consultar inventario\n";
        cout << "3. Alerta de pocas existencias\n4. Entrada o salida\n0. Volver\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: registrarMedicamento(); break;
            case 2: consultarInventario(); break;
            case 3: alertaExistencias(); break;
            case 4: moverInventario(); break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}

void totalPacientes() {
    cout << "Total de pacientes: " << pacientes.size() << endl;
}

void citasPorEstado() {
    int programadas = 0, atendidas = 0, canceladas = 0;
    for (int i = 0; i < citas.size(); i++) {
        if (citas[i].estado == "programada") programadas++;
        else if (citas[i].estado == "atendida") atendidas++;
        else if (citas[i].estado == "cancelada") canceladas++;
    }
    cout << "Programadas: " << programadas << endl;
    cout << "Atendidas: " << atendidas << endl;
    cout << "Canceladas: " << canceladas << endl;
}

void citasPorDoctor() {
    if (doctores.empty()) {
        cout << "No hay doctores registrados.\n";
        return;
    }
    cout << "\n--- CITAS POR DOCTOR ---\n";
    for (int i = 0; i < doctores.size(); i++) {
        int totalCitas = 0;
        for (int j = 0; j < citas.size(); j++) {
            if (citas[j].claveDoctor == doctores[i].clave) {
                totalCitas++;
            }
        }
        cout << "Dr. " << doctores[i].nombre << " (Clave: " << doctores[i].clave 
             << ") - Citas: " << totalCitas << endl;
    }
}

void especialidadConMasCitas() {
    if (doctores.empty() || citas.empty()) {
        cout << "No hay suficientes datos de doctores o citas.\n";
        return;
    }

    string especialidadMax = "";
    int maxCitas = -1;

    for (int i = 0; i < doctores.size(); i++) {
        string espActual = doctores[i].especialidad;
        
        
        bool yaEvaluada = false;
        for (int j = 0; j < i; j++) {
            if (doctores[j].especialidad == espActual) {
                yaEvaluada = true;
                break;
            }
        }
        if (yaEvaluada) continue;

        int citasEsp = 0;
        for (int c = 0; c < citas.size(); c++) {
            for (int d = 0; d < doctores.size(); d++) {
                if (doctores[d].clave == citas[c].claveDoctor && doctores[d].especialidad == espActual) {
                    citasEsp++;
                    break;
                }
            }
        }

        if (citasEsp > maxCitas) {
            maxCitas = citasEsp;
            especialidadMax = espActual;
        }
    }

    if (maxCitas > 0) {
        cout << "La especialidad con mas citas es: " << especialidadMax << " con " << maxCitas << " citas.\n";
    } else {
        cout << "No hay citas registradas para ninguna especialidad.\n";
    }
}

void pacienteConMasCitas() {
    if (pacientes.empty() || citas.empty()) {
        cout << "No hay suficientes datos de pacientes o citas.\n";
        return;
    }

    int maxCitas = -1;
    int expPacienteMax = -1;
    string nombrePacienteMax = "";

    for (int i = 0; i < pacientes.size(); i++) {
        int contador = 0;
        for (int j = 0; j < citas.size(); j++) {
            if (citas[j].expediente == pacientes[i].expediente) {
                contador++;
            }
        }

        if (contador > maxCitas) {
            maxCitas = contador;
            expPacienteMax = pacientes[i].expediente;
            nombrePacienteMax = pacientes[i].nombre;
        }
    }

    if (maxCitas > 0) {
        cout << "El paciente con mas citas es: " << nombrePacienteMax 
             << " (Expediente: " << expPacienteMax << ") con " << maxCitas << " citas.\n";
    } else {
        cout << "Ningun paciente tiene citas registradas.\n";
    }
}

void modulo5() {
    int op;
    do {
        cout << "\n--- MODULO 5: REPORTES ---\n";
        cout << "1. Total de pacientes\n2. Citas por estado\n3. Citas por doctor\n";
        cout << "4. Especialidad con mas citas\n5. Paciente con mas citas\n0. Volver\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: totalPacientes(); break;
            case 2: citasPorEstado(); break;
            case 3: citasPorDoctor(); break;
            case 4: especialidadConMasCitas(); break;
            case 5: pacienteConMasCitas(); break;
            case 0: break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
}

int main() {
    int op;
    do {
        cout << "\n=== SISTEMA HOSPITAL ===\n";
        cout << "1. Pacientes\n2. Doctores\n3. Citas\n4. Medicamentos\n5. Reportes\n0. Salir\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: modulo1(); break;
            case 2: modulo2(); break;
            case 3: modulo3(); break;
            case 4: modulo4(); break;
            case 5: modulo5(); break;
            case 0: cout << "Adios\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (op != 0);
    return 0;
}