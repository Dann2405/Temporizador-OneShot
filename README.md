# Temporizador-OneShot

## Visão Geral do Projeto

O **Temporizador-OneShot** demonstra a implementação de um temporizador de disparo único (*OneShot*) utilizando a função `add_alarm_in_ms()` do **Pico SDK** no microcontrolador **RP2040**. O projeto tem como objetivo controlar LEDs a partir do acionamento de um botão (*pushbutton*), ilustrando de forma prática o uso de temporizadores em sistemas embarcados.

Este projeto pode ser executado tanto no **Wokwi Simulator** (integrado ao **VS Code**) quanto em hardware real, utilizando a placa de desenvolvimento **BitDogLab**.

### Principais Funcionalidades

- **Controle de LEDs via Pushbutton:**  
  - Ao pressionar o botão, todos os LEDs acendem simultaneamente. (Contém um sistema de debounce.)  
  - A cada 3 segundos, um LED é desligado até que todos estejam apagados.  
  - O sistema exemplifica o uso de temporização baseada em eventos.

---

## Requisitos do Sistema

- **Microcontrolador:** Raspberry Pi Pico ou Raspberry Pi Pico W (opcional para execução em hardware real).
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Simulador:** [Wokwi Simulator](https://wokwi.com/) (necessário para testes em ambiente virtual).
- **Ambiente de Desenvolvimento:** Visual Studio Code (VS Code) com extensões adequadas.
- **SDK do Raspberry Pi Pico** corretamente configurado.

---

## Guia de Instalação e Uso

### 1. Clonando o Repositório

Para obter o código-fonte do projeto, utilize o seguinte comando:

```bash
git clone https://github.com/Dann2405/Temporizador-OneShot.git
cd Temporizador-OneShot
```

---

### 2. Configuração do Ambiente

Certifique-se de que o **SDK do Raspberry Pi Pico** está corretamente instalado e configurado no **VS Code**. Além disso, instale as seguintes extensões recomendadas:

- **C/C++** (Microsoft)
- **CMake Tools**
- **Wokwi Simulator** (necessário para simulação no VS Code)
- **[Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)**

---

### 3. Configuração do Projeto no VS Code

1. Abra o projeto no **Visual Studio Code**.
2. Confirme a instalação das extensões recomendadas.
3. Compile o projeto através da interface da extensão do Raspberry Pi Pico:
    - Clique em **"Compile Project"**.
    - O processo gerará um arquivo `.uf2`, necessário para a execução em hardware real e simulação no Wokwi.

---

### 4. Execução no Simulador Wokwi

Para testar o projeto no **Wokwi Simulator**, siga os passos abaixo:

1. Abra o arquivo `diagram.json` no **VS Code**.
2. Clique no botão **"Play"** para iniciar a simulação.
3. O comportamento esperado é:
   - Ao pressionar o pushbutton, todos os LEDs acendem.
   - Após 3 segundos, um LED é desligado.
   - Após mais 3 segundos, outro LED é desligado.
   - Esse processo se repete até que todos os LEDs estejam apagados.
   - O terminal exibirá mensagens indicando que o botão foi pressionado e o OneShot foi iniciado.

---

### 5. Teste em Hardware Real

#### Configuração na Placa **BitDogLab** com **Raspberry Pi Pico W**

1. **Modo de Programação:**
   - Conecte a placa ao computador e entre no modo **BOOTSEL**:
     - Pressione e segure o botão **BOOTSEL** (traseiro da placa).
     - Pressione rapidamente o botão **RESET** (frontal da placa).
     - Após alguns segundos, solte primeiro o botão **RESET** e depois o **BOOTSEL**.
     - A placa será reconhecida como uma unidade de armazenamento.

2. **Compilação e Upload:**
   - No **VS Code**, utilize a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
     - Clique em **"Compile Project"**.
     - Em seguida, clique em **"Run Project USB"** para transferir o código para a placa.

3. **Configuração de Hardware Alternativa:**
   Se não estiver utilizando a BitDogLab, é possível montar o circuito utilizando uma protoboard ou outro microcontrolador, conforme a seguinte pinagem:

   | **Periférico**  | **Pino GPIO** |
   |----------------|--------------|
   | LED Vermelho   | GP13         |
   | LED Azul       | GP12         |
   | LED Verde      | GP11         |
   | Pushbutton     | GP5          |

---

## Considerações Finais

Este projeto exemplifica o uso de temporizadores *OneShot* em sistemas embarcados, possibilitando um entendimento prático e didático da temporização baseada em eventos.
