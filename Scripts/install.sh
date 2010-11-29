set -e

if [-e "$HOME/Library/Application Support/RapidWeaver/${PRODUCT_NAME}.rwplugin"]; then
    rm -rf "$HOME/Library/Application Support/RapidWeaver/${PRODUCT_NAME}.rwplugin"
fi

cp -R "${BUILT_PRODUCTS_DIR}/${PRODUCT_NAME}.rwplugin" "$HOME/Library/Application Support/RapidWeaver"

exit 0;
