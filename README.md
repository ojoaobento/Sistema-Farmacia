## Sistema de Gestão de Farmácia – Vida+

Este projeto tem como objetivo desenvolver um sistema para gerenciamento de uma farmácia, permitindo o controle de clientes, medicamentos, fornecedores, vendas e reposição de estoque.

## 1. Funcionalidades

* Cadastro e gerenciamento de clientes

* Cadastro e gerenciamento de medicamentos

* Cadastro e gerenciamento de fornecedores

* Registro de vendas e emissão de comprovantes

* Controle de estoque e reposição de produtos

* Relatórios básicos de movimentação e estoque

## 2. Pré-requisitos

Para executar este projeto, você precisará ter instalado:

* GCC (compilador C)

* Windows/Linux/Mac (dependendo do ambiente)

* Terminal ou prompt de comando


## 3. Estrutura de Pasta

`````
Sistema-Farmacia/
│
├─ src/           # Código-fonte em C
│   ├─ arquivos em .c
│   ├─ funcoes.h

│
├─ output/        # Executável gerado após compilação e Arquivos com Dados gravados
│   ├─ farmacia.exe
│   ├─ clientes.dat
│   ├─ compras.dat
│   |─ estoque.dat
│   ├─ fornecedor.dat
│   └─ medicamentos.dat
│
└─ README.md      # Documentação do projeto
`````


## 4. Como Compilar e Executar

Abra o terminal na pasta /src e Compile os arquivos C com:

``gcc src/*.c -o output/farmacia.exe``




