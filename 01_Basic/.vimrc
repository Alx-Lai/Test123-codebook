set nu smd ts=2 et cul ai bri scs is hls mouse=a shiftwidth=2
syntax on
filetype indent on
inoremap {<CR> {<CR>}<Esc>ko

map <F9> :call Compile()<CR>
func! Compile()
	exec "w"
  exec "!g++ -Wall -Wshadow -Wextra -g -fsanitize=address % -o %<.out"
endfunc

