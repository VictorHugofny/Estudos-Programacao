SOURCE_FILE_INPUT="$1"

# Verifica se o arquivo de origem foi fornecido
if [ -z "$SOURCE_FILE_INPUT" ]; then
  echo "Nenhum arquivo .c fornecido."
  rm -rf main
  exit 1
fi

# Extrai o nome do arquivo sem a extensão
FILE_NAME="${SOURCE_FILE_INPUT%.c}"

# Nome do arquivo de saída
OUTPUT_FILE="program"

# Compila o arquivo .c para gerar um arquivo objeto
gcc "$FILE_NAME/main.c" $FILE_NAME"/$FILE_NAME.c" "helpers/errors.c" $FILE_NAME/"domain/$FILE_NAME.c" -o $OUTPUT_FILE

# Executa o programa
if [ -f "$OUTPUT_FILE" ]; then
  "./$OUTPUT_FILE"
# Remove os arquivos gerados
  rm -f main $FILE_NAME/main.o $FILE_NAME/*.o "$OUTPUT_FILE"
else
  echo "Erro na compilação ou vinculação. Não foi possível executar o programa."
  rm -f main $FILE_NAME/main.o $FILE_NAME/*.o "$OUTPUT_FILE"
fi
