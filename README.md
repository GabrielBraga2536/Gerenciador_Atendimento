# Gerenciador de Atendimento

Este projeto é um sistema de gerenciamento de atendimentos para pacientes, desenvolvido em C para a disciplina de Estrutura de Dados (CCA230) do Centro Universitário FEI. Este projeto utiliza diversas estruturas de dados como listas duplamente encadeadas, filas, pilhas, árvores binárias de busca (ABB) e heaps.

### Sumário
- [Funcionalidades](#funcionalidades)
- [Estruturas de Dados Utilizadas](#estruturas-de-dados-utilizadas)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Compilação](#compilação)
- [Execução](#execução)
- [Versão do Compilador](#versão-do-compilador)
- [Autores](#autores)

### Funcionalidades

- **Cadastro de Pacientes:** Permite cadastrar, consultar, atualizar e remover pacientes.
- **Atendimento:** Gerencia a fila de atendimento normal e prioriza pacientes conforme a idade.
- **Atendimento Prioritário:** Utiliza uma heap para organizar pacientes prioritários.
- **Pesquisa:** Permite pesquisar registros por ano, mês, dia ou idade.
- **Desfazer Ações:** Possibilita desfazer a última ação realizada na fila de atendimento.
- **Carregar/Salvar:** Carrega e salva listas de pacientes em arquivos.
- **Sobre:** Exibe informações sobre os autores e o projeto.

### Estruturas de Dados Utilizadas

- **LDE (Lista Duplamente Encadeada):** Armazena a lista principal de pacientes.
- **Fila:** Gerencia a ordem de atendimento dos pacientes.
- **Pilha:** Armazena o histórico de ações para desfazer operações.
- **Heap:** Gerencia a fila de atendimento prioritário.
- **ABB (Árvore Binária de Busca):** Permite pesquisas eficientes por diferentes critérios (ano, mês, dia, idade).

### Estrutura do Projeto

- `src/`: Código-fonte dos módulos do sistema.
- `includes/`: Arquivos de cabeçalho (.h) das estruturas e menus.
- `pacientes.txt`: Arquivo de entrada com pacientes de exemplo.
- `pacientesSalvos.txt`: Arquivo de saída para salvar pacientes cadastrados.
- `Makefile`: Script para compilação do projeto.

### Compilação

Para compilar o projeto, utilize o comando no terminal do Windows:

```sh
mingw32-make
```

Se estiver em ambiente Linux, utilize o seguinte comando:

```sh
make
```

O executável gerado será `a.exe` (ou `a` em sistemas Unix).

### Execução

Após compilar, execute o programa:

```sh
./a
```
ou, no Windows:
```sh
a.exe
```

### Versão do Compilador

Durante o desenvolvimento foi utilizado o seguinte compilador:

- GCC: 14.1.0
- GNU Make: 4.4.1 

### Autores

Manuella Valles Egrejas
Gabriel Braga de Souza Otero
