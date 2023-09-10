set nu 'number
syntax on
set smd 'showmode
set ts=2 'tabstop
set shiftwidth=2
set et 'expandtab
set cul 'cursorline
set ai 'autoindent
set bri 'breakindent
filetype indent on
set scs 'smartcase
inoremap {<CR> {<CR>}<Esc>ko
set is 'incsearch
set hls 'hlsearch
set mouse=a

map <F9> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
  exec "!g++ -Wall -Wshadow -Wextra -g -fsanitize=address % -o %<.out"
endfunc

