all: minisat cryptominisat lingeling

LINGELING_VERSION=ayv-86bf266-140429

minisat:
	git clone https://github.com/niklasso/minisat
	@echo ""
	@echo "Minisat fetched."
	@echo ""
	@echo "In the minisat directory do:"
	@echo ""
	@echo "    cmake . && make"
	@echo ""

cryptominisat:
	git clone https://github.com/msoos/cryptominisat.git
	@echo ""
	@echo "CryptoMinisat fetched."
	@echo ""
	@echo "In the cryptominisat directory do:"
	@echo ""
	@echo "    make"
	@echo ""

lingeling:
	curl -o ll.zip http://fmv.jku.at/lingeling/lingeling-$(LINGELING_VERSION).zip
	unzip -d lingeling ll.zip
	$(RM) ll.zip
	@echo ""
	@echo "Lingeling fetched."
	@echo ""
	@echo "In the lingeling directory do:"
	@echo ""
	@echo "    ./build.sh"
	@echo ""
