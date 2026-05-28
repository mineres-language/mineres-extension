import * as vscode from 'vscode';
import * as path from 'path';

export function activate(context: vscode.ExtensionContext) {

    const comando = vscode.commands.registerCommand('mineres.executar', async () => {
        const editor = vscode.window.activeTextEditor;

        if (!editor) {
            vscode.window.showErrorMessage('Nenhum arquivo .uai aberto, uai!');
            return;
        }

        if (editor.document.isDirty) {
            await editor.document.save();
        }

        const arquivoUai  = editor.document.fileName;
        const mainPy      = path.join(context.extensionPath, 'interpreter', 'main.py');
        const python      = process.platform === 'win32' ? 'python' : 'python3';
        const comando_run = `${python} "${mainPy}" "${arquivoUai}"`;

        // Reutiliza o terminal Minerês se já estiver aberto
        let terminal = vscode.window.terminals.find(t => t.name === 'Minerês');
        if (!terminal || terminal.exitStatus !== undefined) {
            terminal = vscode.window.createTerminal('Minerês');
        }

        terminal.show(true); // true = não rouba o foco do editor
        terminal.sendText(comando_run);
    });

    context.subscriptions.push(comando);
}

export function deactivate() {}