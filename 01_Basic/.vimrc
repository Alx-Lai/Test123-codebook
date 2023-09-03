set number
syntax on
set showmode
set tabstop=2
set shiftwidth=2
set expandtab
set cursorline
set autoindent
set breakindent
filetype indent on
set smartcase
inoremap {<CR> {<CR>}<Esc>ko
set incsearch           " Enable incremental search
set hlsearch            " Enable highlight search
set mouse=a             " Enable mouse drag on window splits

map <F9> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
  exec "!g++ -Wall -Wshadow -g -fsanitize=address % -o %<.out"
endfunc

