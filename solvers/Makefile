all: minisat cryptominisat lingeling

LINGELING_VERSION=ayv-86bf266-140429

minisat:
	git clone https://github.com/niklasso/minisat
	$(MAKE) compile_minisat

cryptominisat:
	git clone https://github.com/msoos/cryptominisat.git
	$(MAKE) compile_cryptominisat

lingeling:
	curl -o ll.zip http://fmv.jku.at/lingeling/lingeling-$(LINGELING_VERSION).zip
	unzip -d lingeling ll.zip
	$(RM) ll.zip
	$(MAKE) compile_lingeling

.PHONY: compile_all \
  compile_minisat compile_cryptominisat compile_lingeling

compile_minisat:
	cd minisat && mkdir -p build && cd build && cmake ..
	$(MAKE) -C minisat/build

compile_cryptominisat:
	cd cryptominisat && mkdir -p build && cd build && cmake ..
	$(MAKE) -C cryptominisat/build

compile_lingeling:
	cd lingeling && ./build.sh

compile_all: compile_minisat compile_cryptominisat compile_lingeling
