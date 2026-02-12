#!/usr/bin/env bash

set -e

cd ..
cp RAK-STM32-RUI/package_rak_custom_rui_index.json .
zip -r -9 RAK-STM32-RUI.zip RAK-STM32-RUI/

ZIP_FILE="RAK-STM32-RUI.zip"
JSON_FILE="package_rak_custom_rui_index.json"

# --- Calculate values ---
SIZE=$(stat -c%s "$ZIP_FILE")
SHA256=$(sha256sum "$ZIP_FILE" | awk '{print $1}')
CHECKSUM="SHA-256:$SHA256"

echo "Size: $SIZE"
echo "Checksum: $CHECKSUM"

# --- Update JSON ---
jq --arg size "$SIZE" \
   --arg checksum "$CHECKSUM" \
   '
   .packages[].platforms[] |= (
       .size = $size |
       .checksum = $checksum
   )
   ' "$JSON_FILE" > "$JSON_FILE.tmp"

mv "$JSON_FILE.tmp" "$JSON_FILE"

echo "Updated $JSON_FILE successfully."
