<p align="left"><h1 align="center">A filosofia nunca foi tão mortal 💀</h1></p>
<p align="center">
	<img src="https://img.shields.io/badge/licença-MIT-0b96a2?style=flat&logo=opensourceinitiative&logoColor=white" alt="licença">
	<img src="https://img.shields.io/badge/linguagem-Docker-0b96a2?style=flat&logo=docker&logoColor=white" alt="linguagem-principal">
	<img src="https://img.shields.io/badge/linguagem-Shell-0b96a2?style=flat&logo=gnu-bash&logoColor=white" alt="contagem-linguagens">
	<img src="https://img.shields.io/badge/Norminette-v3.3.51-0b96a2?style=flat&logo=42&logoColor=white" alt="versão-norminette">
</p>

 # 🍝 Philosophers

## 📍 Visão Geral

O projeto **Philosophers** é uma implementação em C do famoso problema dos filósofos jantando, originalmente formulado por Edsger Dijkstra em 1965. Este projeto explora os conceitos fundamentais de **programação concorrente**, **sincronização de threads** e **prevenção de deadlocks**.

### 🎯 Objetivos de Aprendizado

- Compreender os conceitos de **threading** e **mutexes**
- Implementar sincronização de recursos compartilhados
- Prevenir **race conditions** e **deadlocks**
- Gerenciar o tempo de forma precisa em aplicações multi-thread
- Trabalhar com a biblioteca `pthread` em C

## 🧠 O Problema dos Filósofos

### 📖 Descrição do Problema

Um ou mais filósofos sentam-se em uma mesa redonda com um grande prato de espaguete no centro. Cada filósofo tem um garfo, mas precisa de **dois garfos** para comer. Os filósofos alternam entre três estados:

- 🍝 **Comendo**: Precisa segurar dois garfos
- 💤 **Dormindo**: Descansa após comer
- 🤔 **Pensando**: Reflete sobre a vida

### ⚠️ Desafios

- **Deadlock**: Todos os filósofos pegam um garfo e esperam pelo segundo
- **Starvation**: Um filósofo nunca consegue comer
- **Race Conditions**: Acesso simultâneo aos recursos compartilhados

## ✨ Funcionalidades

### 🔧 Parte Obrigatória (philo)

- ✅ Implementação com **threads** e **mutexes**
- ✅ Cada filósofo é uma thread separada
- ✅ Proteção de garfos com mutexes individuais
- ✅ Monitoramento de morte em tempo real
- ✅ Logs formatados com timestamps precisos
- ✅ Prevenção de data races

## 🛠️ Instalação e Uso

### 📋 Pré-requisitos

- **GCC** ou **Clang** compiler
- **Make**
- **pthread** library
- Sistema Unix/Linux

### 🚀 Compilação

```bash
# Clonar o repositório
git clone https://github.com/NaBuchholz/ft_philosophers.git
cd ft_philosophers

# Compilar o projeto
make
```

### 📝 Uso

```bash
# Executar o programa
./philo <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [num_times_must_eat]
```

### 🔍 Parâmetros

- **num_philosophers**: Número de filósofos (e garfos)
- **time_to_die**: Tempo em ms para morrer se não comer
- **time_to_eat**: Tempo em ms necessário para comer
- **time_to_sleep**: Tempo em ms para dormir
- **num_times_must_eat**: (Opcional) Número de vezes que cada filósofo deve comer

### 📊 Exemplos de Uso

```bash
# Cenário básico - 4 filósofos
./philo 4 310 200 100

# Cenário com limite de refeições
./philo 5 800 200 200 7

# Cenário de teste de morte
./philo 1 800 200 200

# Cenário sem mortes
./philo 4 410 200 200
```

## 📁 Estrutura do Projeto

```
ft_philosophers/
├── src/                      # Código fonte
│   ├── actions.c
│   ├── clean.c
│   ├── init.c
│   ├── main.c
│   ├── monitor.c
│   ├── parsing.c
│   ├── philosophers.c
│   ├── take_forks.c
│   ├── time_utils.c
│   └── utils.c
├── includes/                 # Headers
│   └── philo.h
├── Makefile
├── LICENSE
└── README.md
```

## ⚙️ Implementação

### 🧵 Arquitetura

O projeto está organizado de forma modular com as seguintes responsabilidades:

- **main.c**: Ponto de entrada do programa
- **parsing.c**: Validação e processamento dos argumentos
- **init.c**: Inicialização das estruturas e recursos
- **philosophers.c**: Lógica principal dos filósofos
- **actions.c**: Ações dos filósofos (comer, dormir, pensar)
- **take_forks.c**: Gerenciamento de garfos
- **monitor.c**: Monitoramento da simulação
- **time_utils.c**: Utilitários para controle de tempo
- **utils.c**: Funções auxiliares gerais
- **clean.c**: Limpeza de recursos e finalização

### 🔄 Fluxo de Execução

1. **Inicialização**: Parsing de argumentos e setup de estruturas
2. **Criação de Threads**: Uma thread por filósofo + thread monitora
3. **Simulação**: Loop principal de cada filósofo
4. **Monitoramento**: Verificação contínua de condições de parada
5. **Finalização**: Cleanup de recursos

### 🍴 Estratégia Anti-Deadlock

- **Ordenação de garfos**: Filósofos pegam garfos em ordem específica
- **Offset inicial**: Filósofos ímpares começam com delay
- **Monitoramento ativo**: Thread dedicada verifica condições

## 🧪 Testes

### 🔍 Casos de Teste Essenciais

```bash
# Teste de morte básico
./philo 1 800 200 200        # Deve morrer

# Teste sem mortes
./philo 4 410 200 200        # Nenhum deve morrer

# Teste com 2 filósofos
./philo 2 800 200 200        # Edge case importante

# Teste com muitos filósofos
./philo 200 800 200 200      # Teste de performance

# Teste com limite de refeições
./philo 5 800 200 200 7      # Deve parar após 7 refeições cada
```

## 📚 Conceitos Aprendidos

### 🧵 Threading e Sincronização

- **Threads POSIX**: Criação e gerenciamento de threads
- **Mutexes**: Exclusão mútua para recursos compartilhados
- **Semáforos**: Controle de acesso a recursos limitados
- **Race Conditions**: Prevenção de condições de corrida

### 🔒 Problemas de Concorrência

- **Deadlock**: Situações onde threads ficam bloqueadas indefinidamente
- **Starvation**: Quando uma thread nunca consegue acessar recursos
- **Priority Inversion**: Inversão de prioridades em sistemas multi-thread

### ⚡ Otimizações

- **Busca por performance**: Minimizar latência de verificações
- **Uso eficiente de CPU**: Evitar busy waiting desnecessário
- **Gestão de memória**: Prevenção de vazamentos em ambiente multi-thread

## 🐛 Problemas Comuns

### 🔍 Situações Frequentes

1. **Threads não terminam**: Verificar se todos os mutexes são desbloqueados
2. **Mensagens misturadas**: Proteger saída com mutex
3. **Morte não detectada**: Verificar precisão do timing
4. **Vazamentos de memória**: Garantir cleanup adequado

## 📖 Recursos

### 📚 Documentação

- [pthread Manual](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [Mutex Operations](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)
- [Semaphore Operations](https://man7.org/linux/man-pages/man3/sem_wait.3.html)

### 🎓 Materiais de Estudo

- [The Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Deadlock Prevention](https://www.geeksforgeeks.org/deadlock-prevention/)
- [Thread Synchronization](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)

### 🔧 Ferramentas Úteis

- **Valgrind**: Detecção de vazamentos e race conditions
- **GDB**: Debugging de programas multi-thread
- **Helgrind**: Detector de race conditions
- **DRD**: Detector de deadlocks

## 📄 Licença

Este projeto é parte do currículo da **42 School** e está sob a licença MIT.

---

### 📞 Contato

- **GitHub**: [@NaBuchholz](https://github.com/NaBuchholz)
- **42 Intranet**: `nbuchhol`
---

<p align="center">Feito com 💜 por Nyx</p>
